/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:56:03 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/11 13:33:16 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error: wrong numbers of arguments" << std::endl, 1);

	RPN	rpn(argv[1]);
	rpn.resolve();

	return (0);
}


