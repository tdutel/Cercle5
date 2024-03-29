/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:15:34 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/01 10:43:30 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/AForm.hpp"

/* Constructor Destructor */

AForm::AForm(void) : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "\x1b[33mAForm Constructor called.\033[0m" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << "\x1b[33mCopy AForm Constructor called.\033[0m" << std::endl;
}

AForm::AForm(const std::string name) : _name(name), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "\x1b[33mAForm Parametric Constructor called.\033[0m" << std::endl;
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	else if  (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	std::cout << "\x1b[33mAForm Parametric Constructor called.\033[0m" << std::endl;
}

AForm::~AForm()
{
	std::cout << "\x1b[33mAForm Destructor called.\033[0m" << std::endl;
}

// operator //

AForm& AForm::operator=(const AForm& other)
{
	this->_signed = other._signed;
	return (*this);
}

// set //

void	AForm::setSigned(bool sign)
{
	this->_signed = sign;
}


// get //

std::string AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}
int AForm::getGradeExec(void) const
{
	return (this->_gradeExec);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return("\x1b[31mGrade is too high.\033[0m");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return("\x1b[31mGrade is too low.\033[0m");
}

/* Functions */

void	AForm::beSigned(Bureaucrat B)
{
	if (B.getGrade() > getGradeSign())
		throw(GradeTooLowException());
	B.signForm(this);
}

/* Overload Operator */

std::ostream& operator<<(std::ostream &out, const AForm& F)
{
	out << "+---------------------------------------+" << std::endl;
	out << "|                 Form                  |"<< std::endl;
	out << "+---------------------------------------+" << std::endl;
	out << "| Form : \x1b[32m" << F.getName() << "  \033[0m	|" << std::endl;
	out << "| Signed : " << std::boolalpha << F.getSigned() << "   			|"<< std::endl;
	out << "| Grade required to sign it : \x1B[34m" << F.getGradeSign() << " \033[0m	|" << std::endl;
	out << "| Grade required to execute it : \x1B[34m" << F.getGradeExec() << "\033[0m	|" << std::endl;
	out << "+---------------------------------------+" << std::endl;
	return (out);
}

