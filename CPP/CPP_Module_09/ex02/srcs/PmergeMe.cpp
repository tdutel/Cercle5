/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:53:57 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/12 10:01:14 by tdutel           ###   ########.fr       */
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

void	PmergeMe::mergeMe(void)
{
	mergeSort(_vect);
	for (size_t i = 0; _vect[i]; i++)
		std::cout << _vect[i] << ", ";
}

void	PmergeMe::mergeSort(std::vector<int> vect)		//TODO:implementer pour le containeur et faire une fonction pour chaque container instead of generique fonction
{
	int	size = vect.size();
	if (size <= 1)
		return;
	int	middle = size / 2;
	std::vector<int> leftV; // = new int[middle]
	std::vector<int> rightV; //= new int[lengh - middle];

	int	i = 0;
	int	j = 0;
	for(; i < size; i++)
	{
		if (i < middle)
			leftV.push_back(vect[i]);
		else
		{
			rightV.push_back(vect[i]);
			j++;
		}
	}
	mergeSort(leftV);
	mergeSort(rightV);
	merge(leftV, rightV, vect);
}

void	PmergeMe::merge(std::vector<int> leftV, std::vector<int> rightV, std::vector<int> vect)
{
	int leftSize = vect.size() / 2;
	int rightSize = vect.size() - leftSize;
	int i = 0, l = 0, r = 0;

	while(l < leftSize && r < rightSize)
	{
		if (leftV[l] < rightV[r])
		{
			vect[i] = leftV[r];
			i++;
			l++;
		}
		else
		{
			vect[i] = rightV[r];
			i++;
			r++;
		}
	}
	while (l < leftSize)
	{
		vect[i] = leftV[l];
		i++;
		l++;
	}
	while (r < rightSize)
	{
		vect[i] = rightV[r];
		i++;
		r++;
	}
}
