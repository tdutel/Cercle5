/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:33:36 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/26 15:19:01 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>

class ScalarConverter
{

private:
	ScalarConverter(const ScalarConverter &cpy);
// operator //
	ScalarConverter	&operator=(const ScalarConverter &other);
	bool	isNan(const std::string s);
	bool	isNumber(const std::string s);
	bool	isFloat(const std::string s);
	void	exeNan();
	void	exeInt();
	void	exeFloat();

public:

// Construcor //
	ScalarConverter();
	~ScalarConverter();

// function //
	void	convert(std::string str);
	void	type(std::string s);
};


#endif
