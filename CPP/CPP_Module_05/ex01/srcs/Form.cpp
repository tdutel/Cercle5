/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:15:34 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/18 15:30:26 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/Form.hpp"

/* Constructor Destructor */

Form::Form(void) : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "\x1b[33mForm Constructor called.\033[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << "\x1b[33mCopy Form Constructor called.\033[0m" << std::endl;
}

Form::Form(const std::string name) : _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "\x1b[33mForm Parametric Constructor called.\033[0m" << std::endl;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	else if  (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	std::cout << "\x1b[33mForm Parametric Constructor called.\033[0m" << std::endl;
}

Form::~Form()
{
	std::cout << "\x1b[33mForm Destructor called.\033[0m" << std::endl;
}

// operator //

Form& Form::operator=(const Form& other)
{
	this->_signed = other._signed;
	return (*this);
}

// get //

std::string Form::getName(void) const
{
	return (this->_name);
}

int Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}
int Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}


/* Functions */

std::string Form::GradeTooHighException(void)
{
	return("\x1b[31mGrade too high.\033[0m");
}

std::string Form::GradeTooLowException(void)
{
	return("\x1b[31mGrade too low.\033[0m");
}

void	Form::beSigned(Bureaucrat B)
{
	if (B.getGrade() > getGradeSign())
		throw(GradeTooLowException());
	if (this->_signed == false)
	{
		this->_signed = true;
		B.signForm(*this);
	}
	else
		std::cout << "Form is already signed." << std::endl;
	
}


/* Overload Operator */

std::ostream& operator<<(std::ostream &out, const Form& F)
{
	out << "+-----------------------------------+" << std::endl;
	out << "Form \x1b[32m" << F.getName() << "\033[0m," << std::endl;
	out << "signed : " << F.getSigned() << std::endl;
	out << "grade required to sign it : \x1B[34m" << F.getGradeSign() << "\033[0m." << std::endl;
	out << "grade required to execute it : \x1B[34m" << F.getGradeExec() << "\033[0m." << std::endl;
	out << "+-----------------------------------+" << std::endl;
	return (out);
}
