/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:58:35 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/01 10:08:59 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Array.hpp"

int	main()
{
	try
	{
		std::cout << "\x1b[35mTEST 1 : int array\033[0m" << std::endl << std::endl;
		Array<int>	a(10);
		Array<int>	b;

		std::cout << std::endl << "\x1b[32ma size :\033[0m " << a.size() << std::endl;
		std::cout << "\x1b[36mb size :\033[0m " << b.size() << std::endl << std::endl;

		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = i;
			std::cout << "\x1b[32ma[" << i  << "] :\033[0m " << a[i] << std::endl;
		}
		std::cout << std::endl;

		b = a;
		std::cout << std::endl;

		for (size_t i = 0; i < b.size(); i++)
		{
			std::cout << "\x1b[36mb[" << i << "] :\033[0m " << b[i] << std::endl;
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << std::endl << "\x1b[35mTEST 2 : char array\033[0m" << std::endl << std::endl;
		Array<char>	a(10);
		Array<char>	b;

		std::cout << std::endl << "\x1b[32ma size :\033[0m " << a.size() << std::endl;
		std::cout << "\x1b[36mb size :\033[0m " << b.size() << std::endl << std::endl;

		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = i + 65;
			std::cout << "\x1b[32ma[" << i  << "] :\033[0m " << a[i] << std::endl;
		}
		std::cout << std::endl;
		b = a;
		std::cout << std::endl;
		for (size_t i = 0; i < b.size(); i++)
		{
			std::cout << "\x1b[36mb[" << i << "] :\033[0m " << b[i] << std::endl;
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
