/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:02:08 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/26 12:45:07 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"

/* Constructor Destructor */

Bureaucrat::Bureaucrat(void) : _name("default") , _grade(150)
{
	std::cout << "\x1b[33mBureaucrat Constructor called.\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name) , _grade(copy._grade)
{
	std::cout << "\x1b[33mCopy Bureaucrat Constructor called.\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const int grade) : _name("default") , _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if  (grade < 1)
		throw GradeTooHighException();
	std::cout << "\x1b[33mBureaucrat Parametric Constructor called.\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name) , _grade(150)
{
	std::cout << "\x1b[33mBureaucrat Parametric Constructor called.\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name) , _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if  (grade < 1)
		throw GradeTooHighException();
	std::cout << "\x1b[33mBureaucrat Parametric Constructor called.\033[0m" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\x1b[33mBureaucrat Destructor called.\033[0m" << std::endl;
}

// operator //

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other._grade;
	return (*this);
}

/* get set */

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if  (grade < 1)
		throw GradeTooHighException();
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

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return("\x1b[31mGrade is too high.\033[0m");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return("\x1b[31mGrade is too low.\033[0m");
}

/* Functions */

void Bureaucrat::increment(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrement(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
}

/* Overload Operator */

std::ostream& operator<<(std::ostream &out, const Bureaucrat& B)
{
	out << "\x1b[32m" << B.getName() << "\033[0m, bureaucrat \x1B[34mgrade " << B.getGrade() << "\033[0m.";
	return (out);
}
