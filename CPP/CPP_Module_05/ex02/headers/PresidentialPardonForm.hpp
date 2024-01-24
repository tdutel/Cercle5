/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:41:52 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/24 15:43:37 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
public:

// Constructor Destructor //
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &cpy);
	PresidentialPardonForm(const std::string target);
	~PresidentialPardonForm();

// operator //
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);

// get //
     std::string    getTarget();

// function // 
     void      execute(Bureaucrat const & executor) const;

private:

	std::string _target;
};

#endif
