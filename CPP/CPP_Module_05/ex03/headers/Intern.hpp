/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:47:22 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/25 14:30:17 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

public:

// Constructor //
	Intern();
	Intern(const Intern &cpy);
	~Intern();

// operator //
	Intern	&operator=(const Intern &other);

// function //
	AForm *makeForm(std::string name, std::string target);
	std::string unknownForm(std::string name);
private:

};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& B);

#endif