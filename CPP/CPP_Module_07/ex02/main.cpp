/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:58:35 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/05 14:13:25 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Array.hpp"

#define RESET "\033[0m"
#define PURPLE "\x1b[35m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[36m"


#include <string>

//TODO replace inline color flag
int	main()
{
	try
	{
		std::cout << PURPLE << "TEST 1 : int array" << RESET << std::endl << std::endl;
		Array<int>	a(10);
		Array<int>	b;

		std::cout << std::endl << GREEN << "a size : " << RESET << a.size() << std::endl;
		std::cout << BLUE << "b size : " << RESET << b.size() << std::endl << std::endl;
		
		std::cout << "a[] before initiaisation :" << std::endl << std::endl;
		
		for (size_t i = 0; i < a.size(); i++)
			std::cout << GREEN << "a[" << i  << "] : " << RESET << a[i] << std::endl;
		
		std::cout << std::endl << "a[] after initiaisation :" << std::endl << std::endl;

		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = i;
			std::cout << GREEN <<"a[" << i  << "] : " << RESET << a[i] << std::endl;
		}
		std::cout << std::endl;

		b = a;
		std::cout << std::endl << "b[] after assignement :" << std::endl << std::endl;

		for (size_t i = 0; i < b.size(); i++)
		{
			std::cout << BLUE << "b[" << i << "] : " << RESET << b[i] << std::endl;
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << std::endl << PURPLE << "TEST 2 : char array" << RESET << std::endl << std::endl;
		Array<char>	a(10);
		Array<char>	b;

		std::cout << std::endl << GREEN << "a size : " << RESET << a.size() << std::endl;
		std::cout << BLUE << "b size : " << RESET << b.size() << std::endl << std::endl;
		
		std::cout << "a[] before initiaisation :" << std::endl << std::endl;
		
		for (size_t i = 0; i < a.size(); i++)
			std::cout << GREEN << "a[" << i  << "] : " << RESET << a[i] << std::endl;
		
		std::cout << std::endl << "a[] after initiaisation :" << std::endl << std::endl;

		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = i + 65;
			std::cout << GREEN <<"a[" << i  << "] : " << RESET << a[i] << std::endl;
		}
		std::cout << std::endl;

		b = a;
		std::cout << std::endl << "b[] after assignement :" << std::endl << std::endl;

		for (size_t i = 0; i < b.size(); i++)
		{
			std::cout << BLUE << "b[" << i << "] : " << RESET << b[i] << std::endl;
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << std::endl << PURPLE << "TEST 3 : string array" << RESET << std::endl << std::endl;
		Array<std::string>	a(10);
		Array<std::string>	b;

		std::cout << std::endl << GREEN << "a size : " << RESET << a.size() << std::endl;
		std::cout << BLUE << "b size : " << RESET << b.size() << std::endl << std::endl;
		
		std::cout << "a[] before initiaisation :" << std::endl << std::endl;
		
		for (size_t i = 0; i < a.size(); i++)
			std::cout << GREEN << "a[" << i  << "] : " << RESET << a[i] << std::endl;
		
		std::cout << std::endl << "a[] after initiaisation :" << std::endl << std::endl;

		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = "Hello there";
			std::cout << GREEN <<"a[" << i  << "] : " << RESET << a[i] << std::endl;
		}
		std::cout << std::endl;

		b = a;
		std::cout << std::endl << "b[] after assignement :" << std::endl << std::endl;

		for (size_t i = 0; i < b.size(); i++)
		{
			std::cout << BLUE << "b[" << i << "] : " << RESET << b[i] << std::endl;
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
