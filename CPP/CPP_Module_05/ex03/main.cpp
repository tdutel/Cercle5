/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:09 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/25 15:08:58 by tdutel           ###   ########.fr       */
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
		AForm* scf;

		std::cout << std::endl;
		scf = someRandomIntern.makeForm("shrubbery creation", "eh oh la target ou quoi là");
		std::cout << std::endl << *scf << std::endl;

		Bureaucrat B("HighBoy", 1);
		std::cout << std::endl;

		B.signForm(scf);
		B.executeForm(*scf);

		std::cout << std::endl;
		delete (scf);
	}
	catch (const std::string txtException)
	{
		std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	}


	try 
	{
		std::cout << std::endl << std::endl << "\x1b[35mTEST 2 : Robotomy Request Form\033[0m" << std::endl << std::endl;
		Intern someRandomIntern;
		AForm* rrf;

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "eh oh la target ou quoi là");
		std::cout << std::endl << *rrf << std::endl;

		Bureaucrat B("HighBoy", 1);
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


	try 
	{
		std::cout << std::endl << std::endl << "\x1b[35mTEST 3 : Presidential Pardon Form\033[0m" << std::endl << std::endl;
		Intern someRandomIntern;
		AForm* ppf;

		std::cout << std::endl;
		ppf = someRandomIntern.makeForm("presidential pardon", "eh oh la target ou quoi là");
		std::cout << std::endl << *ppf << std::endl;

		Bureaucrat B("HighBoy", 1);
		std::cout << std::endl;

		B.signForm(ppf);
		B.executeForm(*ppf);

		std::cout << std::endl;
		delete (ppf);
	}
	catch (const std::string txtException)
	{
		std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	}


	try 
	{
		std::cout << std::endl << std::endl << "\x1b[35mTEST 4 : Unknown Form\033[0m" << std::endl << std::endl;
		Intern someRandomIntern;
		AForm* uf;
		std::cout << std::endl;
		uf = someRandomIntern.makeForm("unknown name", "eh oh la target ou quoi là");
		std::cout << std::endl << *uf << std::endl;
		Bureaucrat B(1);
		std::cout << std::endl;
		B.signForm(uf);
		B.executeForm(*uf);
		std::cout << std::endl;
		delete (uf);
	}
	catch (const std::string txtException)
	{
		std::cout << std::endl << "\x1b[31mException : \033[0m" << txtException << std::endl;
	}
	return (0);
}
