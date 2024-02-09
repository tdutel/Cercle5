/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:26:16 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/09 14:46:25 by tdutel           ###   ########.fr       */
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
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	
		std::cout << std::endl << "shortestSpan : " << BLUE << sp.shortestSpan() << RESET << std::endl;
		std::cout << "longestSpan : " << RED << sp.longestSpan() << RESET << std::endl;
		
		std::cout << std::endl << "add number(...)" << std::endl;
		sp.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << '\n';
	}

	try
	{
		std::cout << std::endl << PURPLE << "TEST 1 : Span(10 001)." << RESET << std::endl;
		Span sp = Span(10001);
	
		std::cout << std::endl << "add 10 000 nb to tab." << std::endl << std::endl;
		sp.addNumber(sp.getIt(), 10000);
		sp.addNumber(3);
	
		std::cout << std::endl << "shortestSpan : " << BLUE << sp.shortestSpan() << RESET << std::endl;
		std::cout << "longestSpan : " << RED << sp.longestSpan() << RESET << std::endl;
		
		std::cout << std::endl << "add too many number..." << std::endl;
		sp.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << '\n';
	}
return 0;
}

