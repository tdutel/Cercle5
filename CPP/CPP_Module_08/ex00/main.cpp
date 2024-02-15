/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:32:29 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/15 10:05:23 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/easyfind.hpp"

#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	try
	{
		std::cout << PURPLE << "TEST 1 : vector" << RESET << std::endl << std::endl;
		int temp[] = { 1, 1, 1, 1, 2, 2, 1, 3 };
		std::cout << "create " << GREEN << "vector " << RESET << "int a = { 1, 1, 1, 1, 2, 2, 1, 3 }" << std::endl;
		std::vector<int> a;
		a.assign(&temp[0], &temp[8]);
		std::cout << "find the occurence 3 in a." << std::endl;
		std::cout << "occurence found at position : " << easyfind(a, 3) << std::endl << std::endl;

		char tmp2[] = { "hello everyone and welcome." };
		std::cout << "create " << GREEN << "vector " << RESET << "char b = {\"" << tmp2 << "\"}" << std::endl;
		std::vector<char> b;
		b.assign(&tmp2[0], &tmp2[26]);
		std::cout << "find the occurence 'w' in b." << std::endl;
		std::cout << "occurence found at position : " << easyfind(b, 'w') << std::endl << std::endl;

		int tmp3[] = { 1, 2, 3 };
		std::cout << "create " << GREEN << "vector" << RESET << " int err = { 1, 2, 3 }" << std::endl;
		std::vector<int> err;
		err.assign(&tmp3[0], &tmp3[2]);
		std::cout << "find the occurence 4 in err." << std::endl;
		std::cout << easyfind(err, 4) << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << GREY << "Error : " << e.what() << RESET << "\n\n\n";
	}

	try
	{
		std::cout << PURPLE << "TEST 2 : list" << RESET << std::endl << std::endl;
		int temp[] = { 1, 1, 1, 1, 2, 2, 1, 3 };
		std::cout << "create " << YELLOW << "list " << RESET << "int a = { 1, 1, 1, 1, 2, 2, 1, 3 }" << std::endl;
		std::list<int> a;
		a.assign(&temp[0], &temp[8]);
		std::cout << "find the occurence 3 in a." << std::endl;
		std::cout << "occurence found at position : " << easyfind(a, 3) << std::endl << std::endl;

		char tmp2[] = { "hello everyone and welcome." };
		std::cout << "create " << YELLOW << "list " << RESET << "char b = {\"" << tmp2 << "\"}" << std::endl;
		std::list<char> b;
		b.assign(&tmp2[0], &tmp2[26]);
		std::cout << "find the occurence 'w' in b." << std::endl;
		std::cout << "occurence found at position : " << easyfind(b, 'w') << std::endl << std::endl;

		int tmp3[] = { 1, 2, 3 };
		std::cout << "create " << YELLOW << "list " << RESET << "int err = { 1, 2, 3 }" << std::endl;
		std::list<int> err;
		err.assign(&tmp3[0], &tmp3[2]);
		std::cout << "find the occurence 4 in err." << std::endl;
		std::cout << easyfind(err, 4) << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << GREY << "Error : " << e.what() << RESET << "\n\n\n";
	}

	try
	{
		std::cout << PURPLE << "TEST 3 : deque" << RESET << std::endl << std::endl;
		int temp[] = { 1, 1, 1, 1, 2, 2, 1, 3 };
		std::cout << "create " << BLUE << "deque " << RESET << "int a = { 1, 1, 1, 1, 2, 2, 1, 3 }" << std::endl;
		std::deque<int> a;
		a.assign(&temp[0], &temp[8]);
		std::cout << "find the occurence 3 in a." << std::endl;
		std::cout << "occurence found at position : " << easyfind(a, 3) << std::endl << std::endl;

		char tmp2[] = { "hello everyone and welcome." };
		std::cout << "create " << BLUE << "deque " << RESET << "char b = {\"" << tmp2 << "\"}" << std::endl;
		std::deque<char> b;
		b.assign(&tmp2[0], &tmp2[26]);
		std::cout << "find the occurence 'w' in b." << std::endl;
		std::cout << "occurence found at position : " << easyfind(b, 'w') << std::endl << std::endl;

		int tmp3[] = { 1, 2, 3 };
		std::cout << "create " << BLUE << "deque " << RESET << "int err = { 1, 2, 3 }" << std::endl;
		std::deque<int> err;
		err.assign(&tmp3[0], &tmp3[2]);
		std::cout << "find the occurence 4 in err." << std::endl;
		std::cout << easyfind(err, 4) << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << GREY << "Error : " << e.what() << RESET << "\n\n";
	}
	return (0);
}
