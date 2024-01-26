/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:30:43 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/26 15:17:30 by tdutel           ###   ########.fr       */
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
	s.type(argv[1]);
	return (0);
}
