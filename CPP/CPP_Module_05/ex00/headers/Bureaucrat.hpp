/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:00:21 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/15 14:40:34 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{

public:

// Constructor Destructor //
	Bureaucrat();
	Bureaucrat(const Bureaucrat &cpy);
	Bureaucrat(const int grade);
	~Bureaucrat();

// operator //
	Bureaucrat	&operator=(const Bureaucrat &other);

// set //
	void setGrade(int grade);

// get //
	std::string getName(void) const;
	int getGrade(void) const;

// functions //
	void GradeTooHighException();
	void GradeTooLowException();

private:
	const std::string _name;
	int	_grade;
};

#endif

