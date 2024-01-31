/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:47:36 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/31 14:42:59 by tdutel           ###   ########.fr       */
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
	(void)cpy;
	std::cout << "\x1b[33mIntern Copy Constructor called.\033[0m" << std::endl;
}

Intern::~Intern()
{
	std::cout << "\x1b[33mIntern Destructor called.\033[0m" << std::endl;
}

// operator //
Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

// function //
AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string s[] = {"shrubbery creation", "robotomy request" , "presidential pardon"};
	for (size_t i = 0; i < 3; i++)
	{
		if (s[i] == name)
		{
			std::cout << "Intern creates \x1b[32m" << name << "\033[0m form." << std::endl << std::endl;
			AForm *F;
			switch (i)
			{
			case 0:
				F = new ShrubberyCreationForm(target);
				return (F);
			case 1:
				F = new RobotomyRequestForm(target);
				return (F);
			case 2:
				F = new PresidentialPardonForm(target);
				return (F);
			default:
				break;
			}
		}
	}
	throw unknownForm(name);
	return (NULL);
}

std::string	Intern::unknownForm(std::string name)
{
	std::string s = "Form \"\x1b[32m";
	s.append(name);
	s.append("\033[0m\" doesn't exist.\n");
	return(s);
}


/* Overload Operator */
std::ostream& operator<<(std::ostream &out, const Intern& I)
{
	(void)I;
	std::cout << "Intern " << std::endl;
	return (out);
}
