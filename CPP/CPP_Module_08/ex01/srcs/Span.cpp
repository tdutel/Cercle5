/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:19:35 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/07 10:55:56 by tdutel           ###   ########.fr       */
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
		throw std::exception();
	for	(size_t i = 0; i < this->_tab.size(); i++)
		std::cout << "tab[" << i << "] = " << this->_tab[i] << "\t";
	std::cout << std::endl;
}

int		Span::shortestSpan()
{
	Span	cpy(*this);
	std::sort(cpy._tab.begin(), cpy._tab.end());
	// for	(size_t i = 0; i < this->_tab.size(); i++)
	// 	std::cout << "tab[" << i << "] = " << this->_tab[i] << std::endl;
	// std::cout << std::endl;
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
{
	Span	cpy(*this);

	std::sort(cpy._tab.begin(), cpy._tab.end());
	int result = cpy._tab[cpy._max - 1] - cpy._tab[0];
	return (result);
}
}
