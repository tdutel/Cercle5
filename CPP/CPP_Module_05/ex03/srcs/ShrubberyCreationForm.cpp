/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:26:31 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/31 14:39:09 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
	std::cout << "\x1b[33mShrubbery Form Constructor called.\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy._name, cpy._gradeSign, cpy._gradeExec), _target(cpy._target)
{
	std::cout << "\x1b[33mShrubbery Form Copy Constructor called.\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "\x1b[33mShrubbery Form Parametric Constructor called.\033[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\x1b[33mShrubbery Form Destructor called.\033[0m" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	this->_signed = other._signed;
	this->_target = other._target;
	return (*this);
}

// get //

std::string	ShrubberyCreationForm::getTarget()
{
	return (this->_target);
}

// function //

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > 137)
		std::cout << "\x1b[32m" << executor.getName() << "\033[0m couldn't execute \x1b[32m" << getName() << "\033[0m because grade is too low." << std::endl;
	else if (_signed == false)
		std::cout << "\x1b[32m" << executor.getName() << "\033[0m couldn't execute \x1b[32m" << getName() << "\033[0m because it's not signed." << std::endl;
	else
	{
		std::string s1 = _target;
		s1.append("_shrubbery");
		std::ofstream outfile (s1.c_str());
		outfile << "      ,`\"\"\',\n      ;^__^;\n      ;\' ` ;\t\t\t HAPPY CACTUS\n ,,,  ;`,\',;\n;,` ; ;\' ` ;   ,',\n;`,'; ;`,',;  ;,' ;\n;',`; ;` ' ; ;`'`';\n;` '',''` `,',`',;\n `''`'; ', ;`'`'\n      ;' `';\n      ;` ' ;\n      ;' `';\n      ;` ' ;\n      ; ',';\n      ;,' ';\n    \\|/|\\/|\\|/\n     \\\\|/\\|//" << std::endl;
		outfile.close();

	}
}
