/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:20:01 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/31 14:29:59 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include <stdbool.h>
# include <cstdlib>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

public:

// Constructor Destructor //
	AForm();
	AForm(const AForm &cpy);
	AForm(const std::string name);
	AForm(const std::string name, const int gradeSign, const int gradeExec);
	virtual ~AForm();

// operator //
	AForm	&operator=(const AForm &other);

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
	void			beSigned(Bureaucrat B);
	virtual void	execute(Bureaucrat const & executor) const = 0;


protected:
	const	std::string	_name;
	bool				_signed;
	const	int			_gradeSign;
	const	int			_gradeExec;

};

std::ostream&	operator<<(std::ostream &out, const AForm& B);

#endif
