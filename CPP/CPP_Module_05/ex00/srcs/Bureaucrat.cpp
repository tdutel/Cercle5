/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:02:08 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/15 14:52:10 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"

/* Constructor Destructor */

Bureaucrat::Bureaucrat(void)
{
	this->_grade = 1;
	std::cout << "Bureaucrat Constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	this->_grade = copy._grade;
	std::cout << "Copy Bureaucrat Constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const int grade) : _grade(grade)
{
	std::cout << "Bureaucrat Constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called." << std::endl;
}


/* get set */

void	Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}


std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}


/* Functions */

void Bureaucrat::GradeTooHighException(void)
{
	std::cout << "Grade too high" << std::endl;
}

void Bureaucrat::GradeTooLowException(void)
{
	std::cout << "Grade too low" << std::endl;
}
