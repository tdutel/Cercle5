/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:19:35 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/09 14:48:18 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/Span.hpp"

Span::Span(unsigned int N) : _max(N)
{
}

Span::Span(const Span &cpy)
{
	size_t	i = 0;
	while (i < cpy._tab.size())
	{
		this->_tab.push_back(cpy._tab[i]);
		i++;
	}
	this->_max = cpy._max;
}

Span::Span()
{
}

Span::~Span()
{
}


Span& Span::operator=(const Span& other)
{
	size_t	i = 0;
	while(i < other._tab.size())
		this->_tab[i] = other._tab[i];
	this->_max = other._max;
	return (*this);
}

void	Span::addNumber(int	n)
{
	if (this->_tab.size() < this->_max)
		this->_tab.push_back(n);
	else
	{
		throw MaxException();
	}
	if (this->_tab.size() <= 10)
		for	(size_t i = 0; i < this->_tab.size(); i++)
			std::cout << YELLOW << "tab[" << i << "]" << RESET <<  " = " << BLUE << this->_tab[i] << RESET << "\t";
	else
		std::cout << YELLOW << "elements added successfully." << RESET << std::endl;
	std::cout << std::endl;
}

void	Span::addNumber(std::vector<int>::iterator itr, size_t size)
{
	std::vector<int>	v2(size, 0);
	if (this->_tab.size() + size <= this->_max)
		this->_tab.insert(itr, v2.begin(), v2.end());
}

void	Span::addNumber(std::vector<int>::iterator itr, std::vector<int> ve)
{
	if (this->_tab.size() + ve.size() <= this->_max)
	{
		this->_tab.insert(itr, ve.begin(), ve.end());
	}
	else
	{
		throw MaxException();
	}
}

int		Span::shortestSpan()
{
	if (this->_tab.size() <= 1)
		{
			throw MinException();
		}
	Span	cpy(*this);
	std::sort(cpy._tab.begin(), cpy._tab.end());
	size_t i = 0;
	int min = std::min(cpy._tab[i + 1] - cpy._tab[i], cpy._tab[i + 2] - cpy._tab[i + 1]);
	int result = min;
	while (i + 2 < cpy._max)
	{
		min = std::min(cpy._tab[i + 1] - cpy._tab[i], cpy._tab[i + 2] - cpy._tab[i + 1]);
		result = std::min(result, min);
		i++;
	}
	return (result);
}

int		Span::longestSpan()
{
	if (this->_tab.size() <= 1)
		{
			throw MinException();
		}
	Span	cpy(*this);

	std::sort(cpy._tab.begin(), cpy._tab.end());
	int result = cpy._tab[cpy._max - 1] - cpy._tab[0];
	return (result);

}

std::vector<int>::iterator	Span::getIt(void)
{
	return (this->_tab.begin());
};

std::vector<int>::iterator	Span::getIte(void)
{
	return (this->_tab.end());
};


const char*	Span::MinException::what(void) const throw()
{
	return("Error : Not enough numbers !");
};

const char*	Span::MaxException::what(void) const throw()
{
	return("Error : Max numbers reached !");
};
