/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:00:04 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/24 15:03:36 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
public:

// Constructor Destructor //
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &cpy);
	RobotomyRequestForm(const std::string target);
	~RobotomyRequestForm();

// operator //
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);

// get //
     std::string    getTarget();

// function // 
     void      execute(Bureaucrat const & executor) const;

private:

	std::string _target;
};

#endif
