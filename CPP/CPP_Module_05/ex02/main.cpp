/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:09 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/24 15:36:31 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"
#include "headers/AForm.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"

int	main(void)
{
	try 
	{
		std::cout<< "\x1b[35mTEST 1 : Shrubbery Creation Form\033[0m" << std::endl << std::endl;
		AForm *F1 = new ShrubberyCreationForm("file");
		std::cout << std::endl;
		std::cout << *F1 << std::endl;
		std::cout << "create 2 bureaucrats : \x1b[32mExecutor\033[0m and \x1b[32mLowboy\033[0m..." << std::endl << std::endl;
		Bureaucrat	B1("Executor",137);
		Bureaucrat	B2("Lowboy");
		std::cout << std::endl << B1;
		std::cout << B2 << std::endl;
		std::cout << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
		B2.signForm(F1);
		std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
		B2.executeForm(*F1);
		
		std::cout << std::endl << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
		B1.signForm(F1);
		std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
		B1.executeForm(*F1);
		std::cout << std::endl;
	}
	catch (const std::string txtException){
		std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	}
	
	
	std::cout << std::endl << std::endl << std::endl << "\x1b[35mTEST 2 : Robotomy Request Form\033[0m" << std::endl << std::endl << std::endl;
	
	
	try 
	{
		AForm *F1 = new RobotomyRequestForm("file");
		std::cout << std::endl;
		std::cout << *F1 << std::endl;
		std::cout << "create 2 bureaucrats : \x1b[32mExecutor\033[0m and \x1b[32mlowboy\033[0m..." << std::endl << std::endl;
		Bureaucrat	B1("Executor", 45);
		Bureaucrat	B2("Lowboy");
		std::cout << std::endl << B1;
		std::cout << B2 << std::endl;
		std::cout << std::endl << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
		B2.signForm(F1);
		std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
		B2.executeForm(*F1);
		
		std::cout << std::endl << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
		B1.signForm(F1);
		std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
		B1.executeForm(*F1);
		std::cout << std::endl;
	}
	catch (const std::string txtException){
		std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	}
	
	
	
	// try 
	// {
	// 	Bureaucrat	B1("LowBoy", 140);
	// 	Bureaucrat	B2("HighBoy", 1);
	// 	Form F1("law 1", 1, 1);
	// 	std::cout << std::endl;

	// 	std::cout << B1 << std::endl;
	// 	std::cout << B2 << std::endl;
	// 	std::cout << F1 << std::endl;

	// 	B1.signForm(&F1);
	// 	B2.signForm(&F1);
	// 	B2.signForm(&F1);
	// }
	// catch (const std::string txtException){
	// 	std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	// }

	// std::cout<< std::endl << std::endl << std::endl << "\x1b[35mTEST 2 : beSigned() usage\033[0m"<< std::endl << std::endl;

	// try 
	// {
	// 	Bureaucrat	B1("LowBoy", 150);
	// 	Bureaucrat	B2("HighBoy", 140);
	// 	Form F1("law 140", 140, 140);
	// 	std::cout << std::endl;

	// 	std::cout << B1 << std::endl;
	// 	std::cout << B2 << std::endl;
	// 	std::cout << F1 << std::endl;

	// 	std::cout << std::endl << "try to sign \x1b[32m" << F1.getName() << "\033[0m with \x1b[32m" << B2.getName() << "\033[0m..." << std::endl << std::endl;
	// 	F1.beSigned(B2);
	// 	std::cout << std::endl << "try to sign \x1b[32m" << F1.getName() << "\033[0m with \x1b[32m" << B1.getName() << "\033[0m..." << std::endl << std::endl;
	// 	F1.beSigned(B1);
	// }
	// catch (const std::string txtException){
	// 	std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	// }


	// std::cout<< std::endl << std::endl << std::endl << "\x1b[35mTEST 3\033[0m" << std::endl << std::endl;


	// try 
	// {
	// 	std::cout << "try to create a \x1b[32mGrade 0 Form\033[0m..." << std::endl;
	// 	Form	F("Grade0Form", 0, 0);
	// }
	// catch (const std::string txtException){
	// 	std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	// }

	return (0);
}
