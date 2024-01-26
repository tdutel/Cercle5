/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:39:13 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/26 15:46:03 by tdutel           ###   ########.fr       */
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

	// int i = lexical_cast<int>(str);
	// std::cout << "int :" << i << std::endl;
}

void	ScalarConverter::type(std::string s)
{
	if (isNan(s))
		exeNan();
	// else if ()//nombre negatif
	// {}
	switch (isNumber(s))
	{
		case 0 :
			exeNan();
		case 1 :
			exeInt();
		case 2 :
			exeInt();
		case 3 :
			exeDouble(); //pos
		case 4 :
			exeDouble(); //negatif
		case 5 :
			exeFloat(); //pos
		case 6 :
			exeFloat(); //negatif
	}
	else if (isFloat(s))
	{
		exeFloat();
	}
}

// nan = not a number


// check functions //
bool ScalarConverter::isNan(const std::string str)
{
	for (char c : str)
	{
		if (!std::isalpha(c))
			return false;
	}
	return true;
}

// bool ScalarConverter::isNumber(const std::string str)
// {
// 	for (char c : str)
// 	{
// 		if (!std::isdigit(c))
// 			return false;
// 	}
// 	return true;
// }

int	ScalarConverter::isNumber(const std::string str)
{
	int count = 0;
	bool negatif = false;
	if (str.at(0) == '-')
	{
		negatif = true;
		c++;
	}
	for (c : str - 1)
	{
		if (c == '.')
			count++;
		if (!std::isdigit(c) && c != '.')
			return (0);	// nan
	}
	if (str.back() == f)
	if (count == 0 && negatif == false && std::isdigit(str.back()))
		return (1); //int entier
	else if (count == 0 && negatif == true && std::isdigit(str.back()))
		return (2); // int negatif
	else if (count == 1 && negatif == false && std::isdigit(str.back()) )
		return (3); //double pos
	else if (count == 1 && negatif == true && std::isdigit(str.back()) )
		return (4); //double negatif
	else if (count == 1 && negatif == false && str.back() == 'f' )
		return (5); //float pos
	else if (count == 1 && negatif == true && str.back() == 'f' )
		return (6); //float negatif
	else
		return (0);
}

// bool ScalarConverter::isFloat(const std::string str )
// {
// 	for (int i = 0; i < s.size(); i++)
// 		if (s[i] == '.') count++;
// 	if (count != 1)
// 		return (false);
// 	if (str.at(0) == '-' || )
// 	std::istringstream iss(str);
// 	float f;
// 	iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
// 	return iss.eof() && !iss.fail(); 
// }


// exec functions //

void ScalarConverter::exeNan(void)
{
	std::cout << "Nan" << std::endl;
}

void ScalarConverter::exeInt(void)
{
	std::cout << "Int" << std::endl;
}

void ScalarConverter::exeFloat(void)
{
	std::cout << "Float" << std::endl;
}
