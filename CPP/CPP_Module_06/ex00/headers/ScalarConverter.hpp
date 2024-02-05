/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:33:36 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/05 10:46:34 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class ScalarConverter
{

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &cpy);
// operator //
	ScalarConverter	&operator=(const ScalarConverter &other);

// function //
	static int		isChar(const 	std::string str);
	static int		type(const	std::string str);
	static void	exeNan(const	std::string str);
	static void	exeChar(const	std::string str);
	static void	exeInt(const	std::string str);
	static void	exeFloat(const	std::string str);
	static void	exeDouble(const	std::string str);
	static void	print(char c, int i, float f, double d);

public:

// Construcor //
	~ScalarConverter();

// function //
	static void	convert(std::string s);
};

#endif
