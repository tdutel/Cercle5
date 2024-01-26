/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:15:18 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/26 12:49:36 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdbool.h>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:

// Constructor Destructor //
	Form();
	Form(const Form &cpy);
	Form(const std::string name);
	Form(const std::string name, const int gradeSign, const int gradeExec);
	~Form();

// operator //
	Form	&operator=(const Form &other);

// set //

	void	setSigned(bool sign);
	
// get //
	std::string	getName(void) const;
	int			getGradeSign(void) const;
	int			getGradeExec(void) const;
	bool		getSigned(void) const;

// class //
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

// functions //
	void		beSigned(Bureaucrat B);


private:
	const	std::string	_name;
	bool				_signed;
	const	int			_gradeSign;
	const	int			_gradeExec;

};

std::ostream&	operator<<(std::ostream &out, const Form& B);

#endif
