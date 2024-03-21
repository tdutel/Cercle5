#define MAX_EVENTS 10
#include "irc.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/epoll.h>

int main(int argc, char **argv) {
    if (argc != 2)
        return (1);

    uint64_t port = std::strtol(argv[1], NULL, 10);
    int epoll_fd, server_fd, conn_fd, nfds;
    struct epoll_event event, events[MAX_EVENTS];
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    // Création de l'instance epoll
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    // Création du socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Configuration de l'adresse du serveur
    memset(&server_addr, 0, addr_len);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    // Liaison du socket à l'adresse du serveur
    if (bind(server_fd, (struct sockaddr *)&server_addr, addr_len) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Écoute des connexions entrantes
    if (listen(server_fd, SOMAXCONN) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Ajout du socket d'écoute à l'instance epoll
    event.events = EPOLLIN; // Surveillage des événements de lecture
    event.data.fd = server_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    // Surveillance des événements
    while (1) {
        nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (int n = 0; n < nfds; ++n) {
            if (events[n].events & EPOLLIN) {
                if (events[n].data.fd == server_fd) {
                    // Nouvelle connexion entrée
                    conn_fd = accept(server_fd, (struct sockaddr *)&server_addr, &addr_len);
                    if (conn_fd == -1) {
                        perror("accept");
                        continue;
                    }
                    std::cout << "Nouvelle connexion de " << inet_ntoa(server_addr.sin_addr) << std::endl;

                    // Ajout du nouveau descripteur de fichier à l'instance epoll
                    event.events = EPOLLIN;
                    event.data.fd = conn_fd;
                    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_fd, &event) == -1) {
                        perror("epoll_ctl");
                        exit(EXIT_FAILURE);
                    }
                } else {
                    // Traitement des données entrantes sur une connexion existante
                    char buffer[1024];
                    ssize_t bytes_read = read(events[n].data.fd, buffer, sizeof(buffer) - 1);
                    if (bytes_read > 0) {
                        buffer[bytes_read] = '\0'; // Terminer la chaîne
                        std::cout << "Données reçues : " << buffer << std::endl;
                    }
                }
            }
            // else //|| events[n].events & EPOLLOUT
            //     std::cout << "epoll out" << std::endl;
        }
    }
    close(server_fd);
    close(epoll_fd);

    return 0;
}
