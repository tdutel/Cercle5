/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:33:36 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/31 15:16:19 by tdutel           ###   ########.fr       */
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
	ScalarConverter(const ScalarConverter &cpy);
// operator //
	ScalarConverter	&operator=(const ScalarConverter &other);

// function //
	int		isChar(const 	std::string str);
	int		type(const	std::string str);
	void	exeNan(const	std::string str);
	void	exeChar(const	std::string str);
	void	exeInt(const	std::string str);
	void	exeFloat(const	std::string str);
	void	exeDouble(const	std::string str);
	void	print(char c, int i, float f, double d);

public:

// Construcor //
	ScalarConverter();
	~ScalarConverter();

// function //
	void	convert(std::string s);
};

#endif
