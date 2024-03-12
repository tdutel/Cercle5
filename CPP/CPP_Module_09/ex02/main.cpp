/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:56:03 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/12 09:48:06 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cout << "Error: too few arguments" << std::endl, 1);
	PmergeMe	pmm(argc, argv);
	pmm.mergeMe();
	return (0);
}


