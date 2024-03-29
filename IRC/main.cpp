/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:27:58 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/27 15:21:32 by tdutel           ###   ########.fr       */
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
