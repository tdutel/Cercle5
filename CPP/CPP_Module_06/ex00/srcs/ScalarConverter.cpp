/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:39:13 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/31 15:59:52 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScalarConverter.hpp"
// ----------------------------------------Constructor Destructor ----------------------------------------------- //
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
	std::cout << "ScalarConverter Copy Constructor called" << std::endl;
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

// ----------------------------------------Constructor Destructor ----------------------------------------------- //

void	ScalarConverter::convert(std::string s)
{
	switch (type(s))
	{
		case 0 :
			exeNan(s);
			break;
		case 1 :
			exeInt(s);
			break;
		case 2 :
			exeDouble(s);
			break;
		case 3 :
			exeFloat(s);
			break;
	}
}

int	ScalarConverter::isChar(const std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < 32 || str[i] > 126))
			return (-1);
		else if (i > 0)
			return (-1);
	}
	return (0);
}

int	ScalarConverter::type(const std::string str)
{
	int count = 0;
	size_t c = 0;
	if (str[0] == '.')
		return (0);
	if (str[c] == '-')
		c++;
	while (c < str.size() - 1)
	{
		if (str[c] == '.' && std::isdigit(str[c - 1]))
			count++;
		if (!std::isdigit(str[c]) && str[c] != '.')
			return (0);
		c++;
	}
	if (count == 0 && std::isdigit(str[c]))
		return (1);
	else if (count == 1 && std::isdigit(str[c]) )
		return (2);
	else if (count == 1 && std::isdigit(str[c - 1]) && str[c] == 'f' )
		return (3);
	else
		return (0);
}


// exec functions //

void ScalarConverter::exeNan(const std::string str)
{
	if (isChar(str) == 0)
		std::cout << std::fixed << std::setprecision(1) << "char : '" << str << "'" << std::endl;
	else
		std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
	{
		float f = static_cast<float>(std::atof(str.c_str()));
		double d = static_cast<double>(std::atof(str.c_str()));
		std::cout << std::fixed << std::setprecision(1) << "float : " << f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double : " << d << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << "float : nan" << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double : nan" << std::endl;
	}
	
}

void ScalarConverter::exeChar(const	std::string str)
{
	char c = str[0];

	int	i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	print(c, i, f, d);
}

void ScalarConverter::exeInt(const	std::string str)
{
	int i;
	double tmp = std::atof(str.c_str());
	if (tmp < -2147483648)
		i = -2147483648;
	else if (tmp > 2147483647)
		i = 2147483647;
	else
		i = std::atoi(str.c_str());
	char c =  static_cast<char>(tmp);
	float f = static_cast<float>(tmp);
	double d = static_cast<double>(tmp);
	print(c, i, f, d);
}

void ScalarConverter::exeFloat(const	std::string str)
{
	float f = std::atof(str.c_str());

	char c = static_cast<char>(f);
	int	i = static_cast<int>(f);
	double d = static_cast<double>(f);
	print(c, i, f, d);
}

void ScalarConverter::exeDouble(const	std::string str)
{
	double d = std::atof(str.c_str());

	char c = static_cast<char>(d);
	int	i = static_cast<int>(d);
	float f = static_cast<float>(d);
	print(c, i, f, d);
}


void	ScalarConverter::print(char c, int i, float f, double d)
{
	if (c <= 31)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "char : '" << c << "'" << std::endl;
	if (i < -2147483647 || i > 2147483646)
	{
		std::cout << std::fixed << std::setprecision(1) << "int : impossible" << std::endl;
	}
	else 
		std::cout << std::fixed << std::setprecision(1) << "int : " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << d << std::endl;
}
