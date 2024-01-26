/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:33:36 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/26 09:44:39 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{

private:
	ScalarConverter(const ScalarConverter &cpy);
// operator //
	ScalarConverter	&operator=(const ScalarConverter &other);

public:

// Construcor //
	ScalarConverter();
	~ScalarConverter();

// function //
	void	convert(std::string str);
};


#endif
