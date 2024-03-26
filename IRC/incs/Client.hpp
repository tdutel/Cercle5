/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:27:21 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/26 14:32:08 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "Irc.hpp"

class Client
{
	private:
		int	_fd;
		bool	_isInEpoll;
		std::vector<std::string>	_mailbox;
		struct epoll_event	_clientEvent;
		

	public:
		Client(int	connFd);
		~Client();
	
		int			getFd();
		void		setMailbox(std::string str);
		std::string	getMailbox(int at);
		void		clearMailbox();
		void		updateStatus(int epoll_fd);
	
	class err : public std::exception
	{
		public:
			virtual const char* what(void) const throw()
			{
				return ("error.exception");
			}
	};
	
};

#endif
