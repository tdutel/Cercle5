/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:26:16 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/15 10:14:45 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Span.hpp"
#include "headers/Color.hpp"

int main()
{
	try
	{
		std::cout << std::endl << PURPLE << "TEST 1 : Span(5)." << RESET << std::endl;
		Span sp = Span(5);
	
		std::cout << std::endl << "add Number 6, 3, 17, 9, 11 to tab." << RESET << std::endl << std::endl;
		sp.addNumber(6);
		std::cout << GREEN << "current sp size : " << sp.getSize() << RESET << std::endl;
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << GREEN << "current sp size : " << sp.getSize() << RESET << std::endl;
	
		std::cout << std::endl << "shortestSpan : " << BLUE << sp.shortestSpan() << RESET << std::endl;
		std::cout << "longestSpan : " << RED << sp.longestSpan() << RESET << std::endl;
		
		std::cout << std::endl << "add an extra number..." << std::endl;
		sp.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
	}

	try
	{
		std::cout << std::endl << std::endl << PURPLE << "TEST 2 : Span(10 001)." << RESET << std::endl;
		Span sp = Span(10001);

		std::cout << GREEN << "current sp size : " << sp.getSize() << RESET << std::endl;
		std::cout << std::endl << "add 10 000 nb to tab." << std::endl << std::endl;
		sp.addNumber(sp.getIt(), 10000);
		std::cout << GREEN << "current sp size : " << sp.getSize() << RESET << std::endl;
		std::cout << std::endl << "add value 3 to tab." << std::endl << std::endl;
		sp.addNumber(3);
		std::cout << GREEN << "current sp size : " << sp.getSize() << RESET << std::endl;

		std::cout << std::endl << "shortestSpan : " << BLUE << sp.shortestSpan() << RESET << std::endl;
		std::cout << "longestSpan : " << RED << sp.longestSpan() << RESET << std::endl;
		
		std::cout << std::endl << "add an extra number..." << std::endl;
		sp.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
	}

	try
	{
		std::cout << std::endl << std::endl << PURPLE << "TEST 3 : Span(10) + vector." << RESET << std::endl << std::endl;
		Span sp = Span(10);
		std::cout << "adding 3, then 5 to tab." << std::endl << std::endl;
		sp.addNumber(3);
		sp.addNumber(5);

		std::cout << GREEN << std::endl << "current sp size : " << sp.getSize() << RESET << std::endl;
	
		std::cout << std::endl << "adding a vector {1, 1, 1} in front of first element of tab ." << std::endl << std::endl;
		std::vector<int>	vec(3, 1);
		sp.addNumber(sp.getIt(), vec);
		std::cout << std::endl << "shortestSpan : " << BLUE << sp.shortestSpan() << RESET << std::endl;
		std::cout << "longestSpan : " << RED << sp.longestSpan() << RESET << std::endl;

		std::cout << GREEN << std::endl << "current sp size : " << sp.getSize() << RESET << std::endl;

		std::cout << std::endl << "add another value to tab..." << std::endl;
		sp.addNumber(1);
		std::cout << GREEN << "current sp size : " << sp.getSize() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
	}

		try
	{
		std::cout << std::endl << std::endl << PURPLE << "TEST 4 : Span(1) + shortest/longest" << RESET << std::endl << std::endl;
		Span sp = Span(1);
		std::cout << "adding 3 to tab." << std::endl << std::endl;
		sp.addNumber(3);

		std::cout << std::endl << "shortestSpan : " << BLUE << sp.shortestSpan() << RESET << std::endl;
		std::cout << "longestSpan : " << RED << sp.longestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
	}
return 0;
}

