/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:30:43 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/29 11:32:43 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong numbers of arguments." << std::endl;
		return (1);
	}
	ScalarConverter	s;
	std::cout << std::endl;
	s.convert(argv[1]);
	std::cout << std::endl;
	return (0);
}
