/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:32:29 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/02 13:46:23 by tdutel           ###   ########.fr       */
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
		std::cout << "\x1b[35mTEST 1 : vector\033[0m" << std::endl << std::endl;
		int temp[] = { 1, 1, 1, 1, 2, 2, 1, 3 };
		std::cout << "create \x1b[32mvector\033[0m int a = { 1, 1, 1, 1, 2, 2, 1, 3 }" << std::endl;
		std::vector<int> a;
		a.assign(&temp[0], &temp[8]);
		std::cout << "find the occurence 3 in a." << std::endl;
		easyfind(a, 3);
		std::cout << std::endl;

		char tmp2[] = { "hello everyone and welcome." };
		std::cout << "create \x1b[32mvector\033[0m char b = {\"" << tmp2 << "\"}" << std::endl;
		std::vector<char> b;
		b.assign(&tmp2[0], &tmp2[26]);
		std::cout << "find the occurence 'w' in b." << std::endl;
		easyfind(b, 'w');
		std::cout << std::endl;

		int tmp3[] = { 1, 2, 3 };
		std::cout << "create \x1b[32mvector\033[0m int err = { 1, 2, 3 }" << std::endl;
		std::vector<int> err;
		err.assign(&tmp3[0], &tmp3[2]);
		std::cout << "find the occurence 4 in err." << std::endl;
		easyfind(err, 4);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : not found the occurence. (" << e.what() <<")" << "\n\n\n";
	}

	try
	{
		std::cout << "\x1b[35mTEST 2 : list\033[0m" << std::endl << std::endl;
		int temp[] = { 1, 1, 1, 1, 2, 2, 1, 3 };
		std::cout << "create \x1b[33mlist\033[0m int a = { 1, 1, 1, 1, 2, 2, 1, 3 }" << std::endl;
		std::list<int> a;
		a.assign(&temp[0], &temp[8]);
		std::cout << "find the occurence 3 in a." << std::endl;
		easyfind(a, 3);
		std::cout << std::endl;

		char tmp2[] = { "hello everyone and welcome." };
		std::cout << "create \x1b[33mlist\033[0m char b = {\"" << tmp2 << "\"}" << std::endl;
		std::list<char> b;
		b.assign(&tmp2[0], &tmp2[26]);
		std::cout << "find the occurence 'w' in b." << std::endl;
		easyfind(b, 'w');
		std::cout << std::endl;

		int tmp3[] = { 1, 2, 3 };
		std::cout << "create \x1b[33mlist\033[0m int err = { 1, 2, 3 }" << std::endl;
		std::list<int> err;
		err.assign(&tmp3[0], &tmp3[2]);
		std::cout << "find the occurence 4 in err." << std::endl;
		easyfind(err, 4);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : not found the occurence. (" << e.what() <<")" << "\n\n\n";
	}

	try
	{
		std::cout << "\x1b[35mTEST 3 : deque\033[0m" << std::endl << std::endl;
		int temp[] = { 1, 1, 1, 1, 2, 2, 1, 3 };
		std::cout << "create \x1b[34mdeque\033[0m int a = { 1, 1, 1, 1, 2, 2, 1, 3 }" << std::endl;
		std::deque<int> a;
		a.assign(&temp[0], &temp[8]);
		std::cout << "find the occurence 3 in a." << std::endl;
		easyfind(a, 3);
		std::cout << std::endl;

		char tmp2[] = { "hello everyone and welcome." };
		std::cout << "create \x1b[34mdeque\033[0m char b = {\"" << tmp2 << "\"}" << std::endl;
		std::deque<char> b;
		b.assign(&tmp2[0], &tmp2[26]);
		std::cout << "find the occurence 'w' in b." << std::endl;
		easyfind(b, 'w');
		std::cout << std::endl;

		int tmp3[] = { 1, 2, 3 };
		std::cout << "create \x1b[34mdeque\033[0m int err = { 1, 2, 3 }" << std::endl;
		std::deque<int> err;
		err.assign(&tmp3[0], &tmp3[2]);
		std::cout << "find the occurence 4 in err." << std::endl;
		easyfind(err, 4);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : not found the occurence. (" << e.what() <<")" << "\n\n\n";
	}
	return (0);
}

		// std::deque<int>::iterator i;
		// std::cout << *i << std::endl;
		// // int a[] = { 5, 6, 1, 10, 2, 10};
		// // std::vector<int> vect(a, a + 6);

		// std::vector<int> vector1 = {1, 2, 3, 4, 5};
		// easyfind(vector1, 4);
		// const std::vector<int> b = {1, 4, 3, 8, 5};
		// easyfind(b,4);
