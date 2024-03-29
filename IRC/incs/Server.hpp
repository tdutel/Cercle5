/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:09:37 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/26 13:05:48 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "Irc.hpp"
# include "Client.hpp"

# define MAX_EVENTS 10

class Server
{
	private:
		uint64_t _port;
		int _epoll_fd, _server_fd;
		struct sockaddr_in _server_addr;
		socklen_t _addrLen;
		struct epoll_event _event, _events[MAX_EVENTS];
		int _nfds;
		std::map<int, Client*>	_mapClient;

	public:
		Server(char *port);
		~Server();

		void	epollCreation();
		void	socketCreation();
		void	addrConfig();
		void	linkSocket();
		void	listenConnectIn();
		void	addSocketToEpoll();
		void	epollWait();
		void	eventLoop(int n);
		void	epollinEvent(int n);
		void	epollrdhupEvent(int n);
		void	epolloutEvent(int n);
		void	closeFd();
};

#endif
