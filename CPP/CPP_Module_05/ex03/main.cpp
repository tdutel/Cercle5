/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:09 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/25 13:25:34 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"
#include "headers/AForm.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"
#include "headers/Intern.hpp"

int	main(void)
{

	try 
	{
		std::cout<< "\x1b[35mTEST 1 : Shrubbery Creation Form\033[0m" << std::endl << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation", "eh oh la target ou quoi là");
		std::cout << std::endl << *rrf << std::endl;
		Bureaucrat B(1);
		std::cout << std::endl;
		B.signForm(rrf);
		B.executeForm(*rrf);
		std::cout << std::endl;
		delete (rrf);
	}
	catch (const std::string txtException)
	{
		std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	}

	
	// 	AForm *F1 = new ShrubberyCreationForm("Target");
	// 	std::cout << std::endl;
	// 	std::cout << *F1 << std::endl;
	// 	std::cout << "create 2 bureaucrats : \x1b[32mExecutor\033[0m and \x1b[32mLowboy\033[0m..." << std::endl << std::endl;
	// 	Bureaucrat	B1("Executor",137);
	// 	Bureaucrat	B2("Lowboy");
	// 	std::cout << std::endl << B1;
	// 	std::cout << B2 << std::endl;
	// 	std::cout << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
	// 	B2.signForm(F1);
	// 	std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
	// 	B2.executeForm(*F1);
		
	// 	std::cout << std::endl << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
	// 	B1.signForm(F1);
	// 	std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
	// 	B1.executeForm(*F1);
	// 	std::cout << std::endl;
	// 	delete(F1);
	
	
	// std::cout << std::endl << std::endl << std::endl << "\x1b[35mTEST 2 : Robotomy Request Form\033[0m" << std::endl << std::endl << std::endl;
	
	
	// try 
	// {
	// 	AForm *F1 = new RobotomyRequestForm("Target");
	// 	std::cout << std::endl;
	// 	std::cout << *F1 << std::endl;
	// 	std::cout << "create 2 bureaucrats : \x1b[32mExecutor\033[0m and \x1b[32mlowboy\033[0m..." << std::endl << std::endl;
	// 	Bureaucrat	B1("Executor", 45);
	// 	Bureaucrat	B2("Lowboy");
	// 	std::cout << std::endl << B1;
	// 	std::cout << B2 << std::endl;
	// 	std::cout << std::endl << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
	// 	B2.signForm(F1);
	// 	std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
	// 	B2.executeForm(*F1);
		
	// 	std::cout << std::endl << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
	// 	B1.signForm(F1);
	// 	std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
	// 	B1.executeForm(*F1);
	// 	std::cout << std::endl;
	// 	delete(F1);
	// }
	// catch (const std::string txtException){
	// 	std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	// }


	// std::cout << std::endl << std::endl << std::endl << "\x1b[35mTEST 3 : Presidential Pardon Form\033[0m" << std::endl << std::endl << std::endl;


	// try 
	// {
	// 	AForm *F1 = new PresidentialPardonForm("Target");
	// 	std::cout << std::endl;
	// 	std::cout << *F1 << std::endl;
	// 	std::cout << "create 2 bureaucrats : \x1b[32mExecutor\033[0m and \x1b[32mlowboy\033[0m..." << std::endl << std::endl;
	// 	Bureaucrat	B1("Executor", 5);
	// 	Bureaucrat	B2("Lowboy");
	// 	std::cout << std::endl << B1;
	// 	std::cout << B2 << std::endl;
	// 	std::cout << std::endl << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
	// 	B2.signForm(F1);
	// 	std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mLowboy\033[0m..." << std::endl;
	// 	B2.executeForm(*F1);
		
	// 	std::cout << std::endl << "try to sign \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
	// 	B1.signForm(F1);
	// 	std::cout << std::endl << "try to execute \x1b[32m" << F1->getName() << "\033[0m with \x1b[32mExecutor\033[0m..." << std::endl;
	// 	B1.executeForm(*F1);
	// 	std::cout << std::endl;
	// 	delete(F1);
	// }
	// catch (const std::string txtException){
	// 	std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	// }

	return (0);
}
