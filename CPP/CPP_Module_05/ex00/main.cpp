/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:09 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/18 13:25:33 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"

int	main(void)
{
	std::cout<< "\x1b[35mTEST 1\033[0m" << std::endl << std::endl;
	try 
	{
		Bureaucrat	B1("LowBoy");
		Bureaucrat	B2(B1);
		std::cout << std::endl;
		std::cout << (B2) << std::endl;

		std::cout << std::endl << "increment \x1b[32mLowBoy\033[0m copy..." << std::endl << std::endl;
		B2.increment();
		std::cout << (B2) << std::endl;

		std::cout << std::endl << "decrement \x1b[32mLowBoy\033[0m copy..." << std::endl << std::endl;
		B2.decrement();
		std::cout << (B2) << std::endl;

		std::cout << std::endl << "decrement \x1b[32mLowBoy\033[0m copy again..." << std::endl << std::endl;
		B2.decrement();
		std::cout << (B2) << std::endl;
	}
	catch (const std::string txtException){
		std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	}


	std::cout<< std::endl << std::endl << std::endl << "\x1b[35mTEST 2\033[0m"<< std::endl << std::endl;


	try 
	{
		Bureaucrat	B3("HighBoy");
		std::cout << std::endl << (B3) << std::endl;
		std::cout << std::endl << "set \x1B[34mgrade\033[0m to \x1B[34m1\033[0m..." << std::endl;
		B3.setGrade(1);
		std::cout << std::endl << (B3) << std::endl;

		std::cout << std::endl << "increment \x1b[32mHighBoy\033[0m..." << std::endl << std::endl;
		B3.increment();
		std::cout << (B3) << std::endl;
	}
	catch (const std::string txtException){
		std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	}


	std::cout<< std::endl << std::endl << std::endl << "\x1b[35mTEST 3\033[0m" << std::endl << std::endl;


	try 
	{
		std::cout << "try to create a \x1b[32mGrade 0 Boy\033[0m..." << std::endl;
		Bureaucrat	B4("Grade0Boy", 0);
	}
	catch (const std::string txtException){
		std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	}
	return (0);
}
