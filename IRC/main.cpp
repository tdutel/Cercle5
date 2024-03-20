#define MAX_EVENTS 10
#include "irc.hpp"

int main(int argc, char **argv)
{
	int		epoll_fd;
	struct	epoll_event event;
	struct	epoll_event events[MAX_EVENTS];
	char	buffer[1024];

    // Création de l'instance epoll
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    // Ajout de stdin à l'instance epoll
    event.events = EPOLLIN; // Surveillage des événements de lecture
    event.data.fd = STDIN_FILENO;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, &event) == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    // Surveillance des événements
    while (1) {
        int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (int n = 0; n < nfds; ++n) {
            if (events[n].events & EPOLLIN) {
                if (events[n].data.fd == STDIN_FILENO) {
                    // Lecture de la commande entrée par l'utilisateur
                    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                        // Ici, vous pourriez envoyer la commande à un serveur IRC
                        printf("Commande entrée : %s", buffer);
                    }
                }
            }
        }
    }

    close(epoll_fd);

    return 0;
}
