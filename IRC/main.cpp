/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:27:58 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/27 10:28:02 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Irc.hpp"
#include "incs/Server.hpp"
#include "incs/Client.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
		{
			std::cout << "bad numbers of arguments." << std::endl;
			return (1);
		}
	
		Server	Serv(argv[1]);
	
		while (1)
			Serv.epollWait();
		Serv.closeFd();
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
	// uint64_t port = std::strtol(argv[1], NULL, 10);
	// int epoll_fd;
	// int server_fd;
	// int conn_fd;
	// int nfds;
	// struct epoll_event event, events[MAX_EVENTS];
	// struct sockaddr_in server_addr;
	// socklen_t addr_len = sizeof(server_addr);

	// // Création de l'instance epoll
	// epoll_fd = epoll_create1(0);
	// if (epoll_fd == -1) {
	// 	perror("epoll_create1");
	// 	exit(EXIT_FAILURE);
	// }

	// // Création du socket
	// server_fd = socket(AF_INET, SOCK_STREAM, 0);
	// if (server_fd == -1) {
	// 	perror("socket");
	// 	exit(EXIT_FAILURE);
	// }

	// // Configuration de l'adresse du serveur
	// memset(&server_addr, 0, addr_len);
	// server_addr.sin_family = AF_INET;
	// server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	// server_addr.sin_port = htons(port);

	// // Liaison du socket à l'adresse du serveur
	// if (bind(server_fd, (struct sockaddr *)&server_addr, addr_len) == -1) {
	// 	perror("bind");
	// 	exit(EXIT_FAILURE);
	// }

	// // Écoute des connexions entrantes
	// if (listen(server_fd, SOMAXCONN) == -1) {
	// 	perror("listen");
	// 	exit(EXIT_FAILURE);
	// }

	// // Ajout du socket d'écoute à l'instance epoll
	// event.events = EPOLLIN | EPOLLRDHUP; // Surveillage des événements de lecture
	// event.data.fd = server_fd;
	// if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1) {
	// 	perror("epoll_ctl");
	// 	exit(EXIT_FAILURE);
	// }

	// Surveillance des événements
	// while (1) {
		// nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
		// if (nfds == -1) {
		// 	perror("epoll_wait");
		// 	exit(EXIT_FAILURE);
		// }

		// for (int n = 0; n < nfds; ++n) {
			// std::cout << "events = " << events[n].events << "\t EPOLLIN = " << EPOLLIN << std::endl;
			// if (events[n].events & EPOLLIN)
			// {
			// 	if (events[n].data.fd == server_fd) 
			// 	{
			// 		// Nouvelle connexion entrée
			// 		conn_fd = accept(server_fd, (struct sockaddr *)&server_addr, &addr_len);
			// 		if (conn_fd == -1) 
			// 		{
			// 			perror("accept");
			// 			continue;
			// 		}
			// 		std::cout << "Nouvelle connexion de " << inet_ntoa(server_addr.sin_addr) << std::endl;
			// 		// Ajout du nouveau descripteur de fichier à l'instance epoll
			// 		event.events = EPOLLIN | EPOLLRDHUP;
			// 		event.data.fd = conn_fd;
			// 		if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_fd, &event) == -1) 
			// 		{
			// 			perror("epoll_ctl");
			// 			exit(EXIT_FAILURE);
			// 		}
			// 	} 
			// 	else
			// 	{
			// 		// Traitement des données entrantes sur une connexion existante
			// 		char buffer[1024];
			// 		ssize_t bytes_read = read(events[n].data.fd, buffer, sizeof(buffer) - 1);
			// 		if (bytes_read > 0) 
			// 		{
			// 			buffer[bytes_read] = '\0'; // Terminer la chaîne
			// 			std::cout << "Données reçues : " << buffer <<std::endl ;
			// 		}
					
			// 	}
			// }
			// if (events[n].events & EPOLLRDHUP) 
			// 	{
			// 		// Le client s'est déconnecté
			// 		std::cout << "Le client s'est déconnecté." << std::endl;
			// 		close(events[n].data.fd); // Fermer le descripteur de fichier du client déconnecté
			// 		// Supprimer le descripteur de fichier de l'instance epoll si nécessaire
			// 		epoll_ctl(epoll_fd, EPOLL_CTL_DEL, events[n].data.fd, &event);
			// }
		// }
	// }
	// close(server_fd);
	// close(epoll_fd);

	// return 0;
// }
