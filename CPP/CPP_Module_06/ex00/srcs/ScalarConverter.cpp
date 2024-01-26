/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:39:13 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/26 10:57:19 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	std::cout << "ScalarConverter Copy Constructor called" << std::endl;
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	return (*this);
}

void	ScalarConverter::convert(std::string str)
{
	if (isprint(str.at(0)))
	{
		char s = str.at(0);
		std::cout << "char : " << s << std::endl;
	}
	else
		std::cout << "Non displayable" << std::endl;
	int i = static_cast<int>(str);
	std::cout << "int :" << i << std::endl;
}

