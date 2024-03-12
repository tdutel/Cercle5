/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:53:57 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/12 13:27:57 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

int	PmergeMe::parse(char **argv)
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
	clock_t start, start2, end, end2;

	if (parse(argv) == -1)
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
		std::cout << *it.base() << " ";
	std::cout << std::endl;

//	Container Vector : //	

	start = clock();
	mergeSortV(_vect);
	end = clock();


	std::cout << "After:  ";
	for (std::vector<int>::iterator it = _vect.begin(); it < _vect.end(); it++)
		std::cout << *it.base() << " ";
	std::cout << std::endl;

	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << std::setprecision(7) << time_taken << " sec" << std::endl;

//	Container Deque : //

	start2 = clock();
	mergeSortD(_deque);
	end2 = clock();

	double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " << std::fixed << std::setprecision(7) << time_taken2 << " sec" << std::endl;



}

void	PmergeMe::mergeSortV(std::vector<int> &vect)
{
	int	size = vect.size();
	if (size <= 1)
		return;
	int	middle = size / 2;
	std::vector<int> leftV;
	std::vector<int> rightV;

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
	mergeSortV(leftV);
	mergeSortV(rightV);
	mergeV(leftV, rightV, vect);
}

void	PmergeMe::mergeV(std::vector<int> &leftV, std::vector<int> &rightV, std::vector<int> &vect)
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



//	container Deque //


void	PmergeMe::mergeSortD(std::deque<int> &deque)
{
	int	size = deque.size();
	if (size <= 1)
		return;
	int	middle = size / 2;
	std::deque<int> leftD;
	std::deque<int> rightD;

	int	i = 0;
	int	j = 0;
	for(; i < size; i++)
	{
		if (i < middle)
			leftD.push_back(deque[i]);
		else
		{
			rightD.push_back(deque[i]);
			j++;
		}
	}
	mergeSortD(leftD);
	mergeSortD(rightD);
	mergeD(leftD, rightD, deque);
}

void	PmergeMe::mergeD(std::deque<int> &leftD, std::deque<int> &rightD, std::deque<int> &deque)
{
	int leftSize = deque.size() / 2;
	int rightSize = deque.size() - leftSize;
	int i = 0, l = 0, r = 0;

	std::deque<int> newV;
	while(l < leftSize && r < rightSize)
	{
		if (leftD.at(l) < rightD.at(r))
		{
			newV.push_back(leftD[l]);
			l++;
		}
		else
		{
			newV.push_back(rightD[r]);
			r++;
		}
		i++;
	}
	while (l < leftSize)
	{
		newV.push_back(leftD[l]);
		i++;
		l++;
	}
	while (r < rightSize)
	{
		newV.push_back(rightD[r]);
		i++;
		r++;
	}
	deque.clear();
	for (size_t i = 0; i < newV.size(); i++)
	{
		deque.push_back(newV.at(i));
	}
}
