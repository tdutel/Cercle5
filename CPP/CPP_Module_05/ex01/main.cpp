/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:09 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/26 12:46:12 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"
#include "headers/Form.hpp"

int	main(void)
{
	std::cout<< "\x1b[35mTEST 1 : signForm() usage\033[0m" << std::endl << std::endl;
	try 
	{
		Bureaucrat	B1("LowBoy", 140);
		Bureaucrat	B2("HighBoy", 1);
		Form F1("law 1", 1, 1);
		std::cout << std::endl;

		std::cout << B1 << std::endl;
		std::cout << B2 << std::endl;
		std::cout << F1 << std::endl;

		B1.signForm(&F1);
		B2.signForm(&F1);
		B2.signForm(&F1);
	}
	catch (std::exception &e){
		std::cout << std::endl << "\x1b[31mException : \033[0m" <<  e.what() << std::endl;
	}

	std::cout<< std::endl << std::endl << std::endl << "\x1b[35mTEST 2 : beSigned() usage\033[0m"<< std::endl << std::endl;

	try 
	{
		Bureaucrat	B1("LowBoy", 150);
		Bureaucrat	B2("HighBoy", 140);
		Form F1("law 140", 140, 140);
		std::cout << std::endl;

		std::cout << B1 << std::endl;
		std::cout << B2 << std::endl;
		std::cout << F1 << std::endl;

		std::cout << std::endl << "try to sign \x1b[32m" << F1.getName() << "\033[0m with \x1b[32m" << B2.getName() << "\033[0m..." << std::endl << std::endl;
		F1.beSigned(B2);
		std::cout << std::endl << "try to sign \x1b[32m" << F1.getName() << "\033[0m with \x1b[32m" << B1.getName() << "\033[0m..." << std::endl << std::endl;
		F1.beSigned(B1);
	}
	catch (std::exception &e){
		std::cout << std::endl << "\x1b[31mException : \033[0m" <<  e.what() << std::endl;
	}


	std::cout<< std::endl << std::endl << std::endl << "\x1b[35mTEST 3\033[0m" << std::endl << std::endl;


	try 
	{
		std::cout << "try to create a \x1b[32mGrade 0 Form\033[0m..." << std::endl;
		Form	F("Grade0Form", 0, 0);
	}
	catch (std::exception &e){
		std::cout << std::endl << "\x1b[31mException : \033[0m" <<  e.what() << std::endl;
	}

	return (0);
}
