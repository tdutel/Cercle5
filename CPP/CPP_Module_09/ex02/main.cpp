/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:56:03 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/11 15:36:33 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cout << "Error: too few arguments" << std::endl, 1);
	PmergeMe	pmm(argc, argv);
	return (0);
}


// void	mergeSort(int[] array)		//TODO:implementer pour le containeur et faire une fonction pour chaque container instead of generique fonction
// {
// 	int	length = array.length;
// 	if (length <= 1)
// 		return;
// 	int	middle = length / 2;
// 	int[] leftArray = new int[middle];
// 	int[] rightArray = new int[lengh - middle];

// 	int	i = 0;
// 	int	j = 0;

// 	for(; i < length; i++)
// 	{
// 		if (i < middle)
// 			leftArray[i] = array[i];
// 		else
// 		{
// 			rightArray[j] = array[i];
// 			j++;
// 		}
// 	}
// 	mergeSort(leftArray);
// 	mergeSort(rightArray);
// 	merge(leftArray, rightArray, array);
// }

// void	merge(int[] leftArray, int[] rightArray, int[] array)
// {
// 	int leftSize = array.length/ 2;
// 	int rightSize = array.length - leftSize;
// 	int i = 0, l = 0, r = 0;

// 	while(l < leftSize && r < rightSize)
// 	{
// 		if (leftArray[l] < rightArray[r])
// 		{
// 			array[i] = leftArray[r];
// 			i++;
// 			l++;
// 		}
// 		else
// 		{
// 			array[i] = rightArray[r];
// 			i++;
// 			r++;
// 		}
// 	}
// 	while (l < leftSize)
// 	{
// 		array[i] = leftArray[l];
// 		i++;
// 		l++;
// 	}
// 	while (r < rightSize)
// 	{
// 		array[i] = rightArray[r];
// 		i++;
// 		r++;
// 	}
// }
