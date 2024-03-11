/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:53:57 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/11 15:47:30 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char**argv)
{
	if (parseVect(argv) == -1)
		{
			std::cout << "Error." << std::endl;
			return ;
		}
	for (int i = 1; i < argc; i++)
	{
			_vect.insert(_vect.end(), std::atoi(argv[i]));
	}

	for (size_t i = 0; _vect[i]; i++)
		std::cout << _vect[i] << "\t";
}

PmergeMe::~PmergeMe()
{
}

int	PmergeMe::parseVect(char **argv)
{
	for (size_t i = 1; argv[i]; i++)
	{
		for (size_t j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
				return (-1);
		}
	}
	return (0);
}
