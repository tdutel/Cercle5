/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:26:26 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/11 12:47:28 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RPN.hpp"

RPN::RPN(std::string str) : _str(str)
{
	if (validExpress(_str) == -1)
		std::cout << "Error." << std::endl;
};

RPN::~RPN()
{
};

void	RPN::prints()
{
	std::cout << _str <<  std::endl;
}

// void	RPN::fillStack()
// {
// 	_stack
// }

// while (isdigit(_str[i]) )
// _stack.push_back()
// if is opperator
// pop 2
// calcul
// push result on stack

int	RPN::validChar(std::string str)
{
	size_t i = 0;
	while (str[i])
	{
		// std::cout << str[i] << std::endl;
		if ((str[i] < '0' && (str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')) || (str[i] > '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	RPN::validExpress(std::string str)
{
	if (validChar(str) == -1)
		return (-1);
	for (size_t i = 0; str[i] ; i++)
	{
		if (str[i] != ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			return (std::cout << "err:" << str[i] << std::endl, -1);
	}
	return (0);
}
