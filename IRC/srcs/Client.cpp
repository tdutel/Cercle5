/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:27:16 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/26 14:57:14 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Client.hpp"

Client::Client(int	fd) : _fd(fd), _isInEpoll(false)
{
	_clientEvent.events = EPOLLIN | EPOLLRDHUP;
}

Client::~Client()
{
}

int	Client::getFd()
{
	return (_fd);
}

void	Client::setMailbox(std::string str)
{
	_mailbox.push_back(str);
}

std::string	Client::getMailbox(int at)
{
	return (_mailbox.at(at));
}

void	Client::clearMailbox()
{
	_mailbox.clear();
}

void	Client::updateStatus(int epoll_fd)
{
	if (_isInEpoll == false)
	{
		if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, _fd, &_clientEvent) == -1)
		{
			perror("epoll_ctl");
			throw err();
			// exit(EXIT_FAILURE);	//TODO: throw exception
		}
	}
}
