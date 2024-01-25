/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:47:36 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/25 13:41:02 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Intern.hpp"

// Constructor //

Intern::Intern()
{
	std::cout << "\x1b[33mIntern Constructor called.\033[0m" << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	std::cout << "\x1b[33mIntern Copy Constructor called.\033[0m" << std::endl;
}

Intern::~Intern()
{
	std::cout << "\x1b[33mIntern Destructor called.\033[0m" << std::endl;
}

// operator //
Intern& Intern::operator=(const Intern &other)
{
	return (*this);
}

// function //
AForm* Intern::makeForm(std::string name, std::string target)
{
	if (name == "presidential pardon" || name == "robotomy request" || name == "shrubbery creation")
		std::cout << "Intern creates \x1b[32m" << name << "\033[0m." << std::endl << std::endl;
	if (name == "shrubbery creation")
	{
		AForm *F = new ShrubberyCreationForm(target);
		return (F);
	}
	if (name == "robotomy request")
	{
		AForm *F = new RobotomyRequestForm(target);
		return (F);
	}
	if (name == "presidential pardon")
	{
		AForm *F = new PresidentialPardonForm(target);
		return (F);
	}
	throw unknownForm(name);
	return (NULL);
}

std::string	Intern::unknownForm(std::string name)
{
	std::string s = "Form \x1b[32m";
	s.append(name);
	s.append("\033[0m doesn't exist.\n");
	return(s);
}
