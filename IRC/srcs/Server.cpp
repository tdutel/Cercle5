/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:10:07 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/25 15:42:54 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Server.hpp"

Server::Server(char *port) : _port(std::strtol(port, NULL, 10)), _addrLen(sizeof(_server_addr))
{
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
		perror("epoll_create1");
		exit(EXIT_FAILURE);
	}
}

		// Création du socket
void	Server::socketCreation()
{
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_server_fd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
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
		perror("bind");
		exit(EXIT_FAILURE);
	}
}


		// Écoute des connexions entrantes
void	Server::listenConnectIn()
{
	if (listen(_server_fd, SOMAXCONN) == -1) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
}

		// Ajout du socket d'écoute à l'instance epoll
void	Server::addSocketToEpoll()
{
	_event.events = EPOLLIN | EPOLLRDHUP; // Surveillage des événements de lecture
	_event.data.fd = _server_fd;
	if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _server_fd, &_event) == -1) {
		perror("epoll_ctl");
		exit(EXIT_FAILURE);
	}
}

void	Server::epollWait()
{
	_nfds = epoll_wait(_epoll_fd, _events, MAX_EVENTS, -1);
		if (_nfds == -1) {
			perror("epoll_wait");
			exit(EXIT_FAILURE);
		}
	for (int n = 0; n < _nfds; ++n)
		eventLoop(n);
}

void	Server::eventLoop(int	n)
{
	if (_events[n].events & EPOLLIN)
			{
				if (_events[n].data.fd == _server_fd) 
				{
					// Nouvelle connexion entrée
					
					int connFd = accept(_server_fd, (struct sockaddr *)&_server_addr, &_addrLen);
					Client *acceptedClient = new Client(connFd);
					
					_mapClient[acceptedClient->getFd()] = acceptedClient;
					if (connFd == -1) 
					{
						perror("accept");
						// continue;
					}
					std::cout << "Nouvelle connexion de " << inet_ntoa(_server_addr.sin_addr) << std::endl;
					// Ajout du nouveau descripteur de fichier à l'instance epoll
					_event.events = EPOLLIN | EPOLLRDHUP;
					_event.data.fd = connFd;
					if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, connFd, &_event) == -1) 
					{
						perror("epoll_ctl");
						exit(EXIT_FAILURE);
					}
				} 
				else
				{
					// Traitement des données entrantes sur une connexion existante
					char buffer[1024];
					ssize_t bytes_read = read(_events[n].data.fd, buffer, sizeof(buffer) - 1);
					if (bytes_read > 0) 
					{
						buffer[bytes_read] = '\0'; // Terminer la chaîne
						std::cout << "Données reçues : " << buffer <<std::endl ;
					}
					
				}
			}
			if (_events[n].events & EPOLLRDHUP) 
				{
					// Le client s'est déconnecté
					std::cout << "Le client s'est déconnecté." << std::endl;
					close(_events[n].data.fd); // Fermer le descripteur de fichier du client déconnecté
					// Supprimer le descripteur de fichier de l'instance epoll si nécessaire
					epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, _events[n].data.fd, &_event);
			}
}

void	Server::closeFd()
{
	close(_server_fd);
	close(_epoll_fd);
}
