/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:19:35 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/05 09:46:36 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/Span.hpp"

Span::Span(unsigned int N)
{
	_tab = new	int[N];
}

Span::Span(const Span &cpy)
{
	int N = len(cpy._tab);
	_tab = new	int[N];
	for (int i = 0; i < N; i++)
		_tab[i] = cpy._tab[i];
}

Span::~Span()
{
	delete[] _tab;
}


Span& Span::operator=(const Span& other)
{
	int N = len(other._tab);
	_tab = new	int[N];
	for (int i = 0; i < N; i++)
		_tab[i] = other._tab[i];
	return (*this);
}

void	Span::addNumber(int	n)
{
	size_t i = 0;
	while(_tab[i])
		i++;
	_tab[i] = n;
}

int		Span::shortestSpan()
{
	return (0);
}

int		Span::longestSpan()
{
	return (0);
}

int	Span::getNb(unsigned int n)
{
	return _tab[n];
}

int	*Span::getTab()
{
	return (_tab);
}

int	Span::len(int *_tab)
{
	int i = 0;
	while (_tab[i])
		i++;
	return (i);
}
