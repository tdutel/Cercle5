/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:56:03 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/08 14:44:34 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/BitcoinExchange.hpp"



int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error: wrong numbers of arguments" << std::endl, 1);

	std::ifstream infile;

	infile.open(argv[1]);
	if (!infile.is_open())
		return (std::cout << "Error: unknown file : " << argv[1] << std::endl, 1);

	BitcoinExchange	btc(argv[1]);

	btc.controlMap();
	return (0);
}
