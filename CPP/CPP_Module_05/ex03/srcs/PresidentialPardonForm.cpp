/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:42:14 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/24 15:56:05 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{
	std::cout << "\x1b[33mPresidential Form Constructor called.\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy._name, cpy._gradeSign, cpy._gradeExec), _target(cpy._target)
{
	std::cout << "\x1b[33mPresidential Form Copy Constructor called.\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "\x1b[33mPresidential Form Parametric Constructor called.\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\x1b[33mPresidential Form Destructor called.\033[0m" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	this->_signed = other._signed;
	this->_target = other._target;
	return (*this);
}

// get //

std::string	PresidentialPardonForm::getTarget()
{
	return (this->_target);
}

// function //

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > 5)
		std::cout << "\x1b[32m" << executor.getName() << "\033[0m couldn't execute \x1b[32m" << getName() << "\033[0m because grade is too low." << std::endl;
	else if (_signed == false)
		std::cout << "\x1b[32m" << executor.getName() << "\033[0m couldn't execute \x1b[32m" << getName() << "\033[0m because it's not signed." << std::endl;
	else
	{
		std::cout << "\x1b[32m" << _target << "\033[0m has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}
