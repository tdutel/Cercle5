/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:10:07 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/28 11:45:03 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Server.hpp"

Server::Server(char *port) : _addrLen(sizeof(_server_addr))
{
	std::string str(port);
	if (std::string::npos != str.find_first_not_of("0123456789"))
		throw	std::invalid_argument("Error : port is not valid.");
	_port = std::strtol(port, NULL, 10);
	epollCreation();
	socketCreation();
	addrConfig();
	linkSocket();
	listenConnectIn();
	addSocketToEpoll();
}

Server::~Server()
{
}

		// Création de l'instance epoll
void	Server::epollCreation()
{
	_epoll_fd = epoll_create1(0);
	if (_epoll_fd == -1) {
		throw std::runtime_error("Error while calling epoll_create1().");
	}
}

		// Création du socket
void	Server::socketCreation()
{
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_server_fd == -1) {
		throw std::runtime_error("Error while creating socket.");
	}
	int option = 1;
	setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

}

		// Configuration de l'adresse du serveur
void	Server::addrConfig()
{
	memset(&_server_addr, 0, _addrLen);
	_server_addr.sin_family = AF_INET;
	_server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	_server_addr.sin_port = htons(_port);
}

		// Liaison du socket à l'adresse du serveur
void	Server::linkSocket()
{
	if (bind(_server_fd, (struct sockaddr *)&_server_addr, _addrLen) == -1) {
		throw std::runtime_error("Error while binding socket.");
	}
}


		// Écoute des connexions entrantes
void	Server::listenConnectIn()
{
	if (listen(_server_fd, SOMAXCONN) == -1) {
		throw std::runtime_error("Error while listening.");
	}
}

		// Ajout du socket d'écoute à l'instance epoll
void	Server::addSocketToEpoll()
{
	_event.events = EPOLLIN | EPOLLRDHUP | EPOLLOUT; // Surveillage des événements de lecture
	_event.data.fd = _server_fd;
	if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _server_fd, &_event) == -1) {
		throw std::runtime_error("Error while calling epoll_ctl().");
	}
}

void	Server::epollWait()
{
	_nfds = epoll_wait(_epoll_fd, _events, MAX_EVENTS, -1);
		if (_nfds == -1) {
			throw std::runtime_error("Error while calling epoll_wait().");
		}
	for (int n = 0; n < _nfds; ++n)
		eventLoop(n);
}

void	Server::eventLoop(int	n)
{
	try
	{
		if (_events[n].events & EPOLLRDHUP)
			epollrdhupEvent(n);
		else if (_events[n].events & EPOLLIN)
			epollinEvent(n);
		else if (_events[n].events & EPOLLOUT)
			epolloutEvent(n);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Server::epollinEvent(int n)
{
	if (_events[n].data.fd == _server_fd) 
	{
		// Nouvelle connexion entrée
		
		int connFd = accept(_server_fd, (struct sockaddr *)&_server_addr, &_addrLen);
		if (connFd == -1)
		{
			throw std::runtime_error("Error while calling accept().");
		}
		Client *acceptedClient = new Client(connFd);
		
		_mapClient[acceptedClient->getFd()] = acceptedClient;
		// Ajout du nouveau descripteur Client de fichier à l'instance epoll
		_mapClient[acceptedClient->getFd()]->updateStatus(_epoll_fd);
		
		// std::cout << "Nouvelle connexion de " << inet_ntoa(_server_addr.sin_addr) << std::endl;
		std::stringstream buff;
		buff << "Nouvelle connexion de " << inet_ntoa(_server_addr.sin_addr) << "\r\n";
		std::map<int, Client *>::iterator curClient = _mapClient.find(connFd);
		for (std::map<int, Client *>::iterator it = _mapClient.begin(); it != _mapClient.end(); it++)
		{
			if (it != curClient)
				it->second->setMailbox(buff.str(), _epoll_fd);	//ajout de l'input dans la mailbox
		}
	}
	else
	{
		// Traitement des données entrantes sur une connexion existante
		char buffer[1024] = {0};
		// ssize_t bytes_read = read(_events[n].data.fd, buffer, sizeof(buffer) - 1);
		ssize_t bytes_read = recv(_events[n].data.fd, buffer, sizeof(buffer) - 1, 0);
		if (bytes_read > 0) 
		{
			std::map<int, Client *>::iterator curClient = _mapClient.find(_events[n].data.fd);
			buffer[bytes_read] = '\0'; // Terminer la chaîne
			for (std::map<int, Client *>::iterator it = _mapClient.begin(); it != _mapClient.end(); it++)
			{
				if (it != curClient)
					it->second->setMailbox(buffer, _epoll_fd);	//ajout de l'input dans la mailbox
			}

			// std::cout << "Client "<< _events[n].data.fd <<" : " << buffer <<std::endl ;
		}

	}
}

void	Server::epollrdhupEvent(int n)
{
	std::stringstream buff;
	buff << "Le client " << _events[n].data.fd << " s'est déconnecté.\r\n";
	
	std::map<int, Client *>::iterator curClient = _mapClient.find(_events[n].data.fd);
	for (std::map<int, Client *>::iterator it = _mapClient.begin(); it != _mapClient.end(); it++)
	{
		if (it != curClient)
			it->second->setMailbox(buff.str(), _epoll_fd);	//ajout de l'input dans la mailbox
	}

	// Le client s'est déconnecté
	// Supprimer le descripteur de fichier de l'instance epoll si nécessaire
	epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, _events[n].data.fd, &_event);
	close(_events[n].data.fd); // Fermer le descripteur de fichier du client déconnecté
	delete(_mapClient[_events[n].data.fd]);
	_mapClient.erase(_events[n].data.fd);
	// _mapClient[_events[n].data.fd]->updateStatus(_epoll_fd);
}

void	Server::epolloutEvent(int n)
{
	_mapClient[_events[n].data.fd]->receiveAll(_epoll_fd);
}

void	Server::closeFd()
{
	close(_server_fd);
	close(_epoll_fd);
}


/*
//TODO: deconnecter le client si catch un throw dans le client ?
*/
