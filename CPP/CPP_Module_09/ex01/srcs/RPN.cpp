/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:26:26 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/13 15:20:18 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RPN.hpp"

RPN::RPN(std::string str) : _str(str)
{
};

RPN::~RPN()
{
};

void	RPN::resolve()
{
	if (validExpression(_str) == -1)
	{
		std::cout << "Error" << std::endl;
		return;
	}
	size_t	i = 0;
	while (_str[i])
	{
		
		while(_str[i] != '+' && _str[i] != '-' && _str[i] != '*' && _str[i] != '/')
		{
			if (_str[i]== '\0')
			{
				std::cout << "Error" << std::endl;
				return ;
			}
			if (isdigit(_str[i]))
				_stack.push(_str[i]);
			i++;
		}
		int	b = _stack.top() - 48;
		_stack.pop();
		int	a = _stack.top() - 48;
		_stack.pop();
		int result;
		switch (_str[i])
		{
		case 43:
			result = a + b;
			break;

		case 45:
			result = a - b;
			break;

		case 42:
			result = a * b;
			break;

		case 47:
		if (b == 0)
		{
			std::cout << "Error" << std::endl;
			return;
		}
			result = a / b;
			break;
		}
		_stack.push(result + 48);
		i++;
	}
	std::cout<< _stack.top() - 48 << std::endl;
}

int	RPN::validExpression(std::string str)
{
	if (std::string::npos == str.find_first_of("0123456789"))
		return (-1);
	if (!isdigit(str[0]) || (isdigit(str[0]) && !isdigit(str[2])))
		return (-1);
	for (size_t i = 0; str[i] ; i++)
	{
		if ((str[i] < '0' && (str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')) || (str[i] > '9'))
			return (-1);
	}

	for (size_t i = 0; str[i] ; i++)
	{
		if (str[i] != ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			return (-1);
	}

	int	d = 0;
	int	o = 0;

	for (size_t i = 0; str[i] ; i++)
	{
		if (isdigit(str[i]))
			d++;
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			o++;
	}
	if (d <= o)
		return (-1);

	return (0);
}
