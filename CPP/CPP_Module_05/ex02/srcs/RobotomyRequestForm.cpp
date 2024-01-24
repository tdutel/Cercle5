/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:02:07 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/24 15:55:29 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
	std::cout << "\x1b[33mRobotomy Form Constructor called.\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy._name, cpy._gradeSign, cpy._gradeExec), _target(cpy._target)
{
	std::cout << "\x1b[33mRobotomy Form Copy Constructor called.\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "\x1b[33mRobotomy Form Parametric Constructor called.\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\x1b[33mRobotomy Form Destructor called.\033[0m" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	this->_signed = other._signed;
	this->_target = other._target;
	return (*this);
}

// get //

std::string	RobotomyRequestForm::getTarget()
{
	return (this->_target);
}

// function //

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > 45)
		std::cout << "\x1b[32m" << executor.getName() << "\033[0m couldn't execute \x1b[32m" << getName() << "\033[0m because grade is too low." << std::endl;
	else if (_signed == false)
		std::cout << "\x1b[32m" << executor.getName() << "\033[0m couldn't execute \x1b[32m" << getName() << "\033[0m because it's not signed." << std::endl;
	else
	{
		srand(time(0));
		int	x = rand() % 2;
		if (x == 0)
			std::cout << "\x1b[32m" << _target << "\033[0m has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomy failed." << std::endl;
	}
}
