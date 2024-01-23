/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:26:15 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/23 15:47:40 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:

// Constructor Destructor //
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
	ShrubberyCreationForm(const std::string name);
	~ShrubberyCreationForm();

// operator //
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
};

#endif
