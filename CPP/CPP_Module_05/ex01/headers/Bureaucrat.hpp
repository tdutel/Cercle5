/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:21 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/23 14:12:57 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdbool.h>
# include "Form.hpp"

class Form;

class Bureaucrat
{

public:

// Constructor Destructor //
	Bureaucrat();
	Bureaucrat(const Bureaucrat &cpy);
	Bureaucrat(const std::string name);
	Bureaucrat(const int grade);
	Bureaucrat(const std::string name, const int grade);
	~Bureaucrat();

// operator //
	Bureaucrat	&operator=(const Bureaucrat &other);

// set //
	void	setGrade(int grade);

// get //
	std::string	getName(void) const;
	int			getGrade(void) const;

// functions //
	std::string	GradeTooHighException();
	std::string	GradeTooLowException();
	void		increment();
	void		decrement();
	void		signForm(Form *F);


private:
	const std::string	_name;
	int					_grade;
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& B);


#endif

