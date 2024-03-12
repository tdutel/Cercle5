/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:53:57 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/12 12:03:17 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
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

void	PmergeMe::mergeMe(int argc, char**argv)
{
	clock_t start, end;

	if (parseVect(argv) == -1)
		{
			std::cout << "Error." << std::endl;
			return ;
		}
	for (int i = 1; i < argc; i++)
	{
			_vect.push_back(std::atoi(argv[i]));
	}
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = _vect.begin(); it < _vect.end(); it++)
	{
		std::cout << *it.base() << " ";
	}
	std::cout << std::endl;
	
	start = clock();
	mergeSort(_vect);
	end = clock();

	std::cout << "After:  ";
	for (std::vector<int>::iterator it = _vect.begin(); it < _vect.end(); it++)
	{
		std::cout << *it.base() << " ";
	}
	std::cout << std::endl;

	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << time_taken << std::setprecision(10) << " us" << std::endl;
}

void	PmergeMe::mergeSort(std::vector<int> &vect)		//TODO:implementer pour le containeur et faire une fonction pour chaque container instead of generique fonction
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

void	PmergeMe::merge(std::vector<int> &leftV, std::vector<int> &rightV, std::vector<int> &vect)
{
	int leftSize = vect.size() / 2;
	int rightSize = vect.size() - leftSize;
	int i = 0, l = 0, r = 0;

	std::vector<int> newV;
	while(l < leftSize && r < rightSize)
	{
		if (leftV.at(l) < rightV.at(r))
		{
			newV.push_back(leftV[l]);
			l++;
		}
		else
		{
			newV.push_back(rightV[r]);
			r++;
		}
		i++;
	}
	while (l < leftSize)
	{
		newV.push_back(leftV[l]);
		i++;
		l++;
	}
	while (r < rightSize)
	{
		newV.push_back(rightV[r]);
		i++;
		r++;
	}
	vect.clear();
	for (size_t i = 0; i < newV.size(); i++)
	{
		vect.push_back(newV.at(i));
	}
}
