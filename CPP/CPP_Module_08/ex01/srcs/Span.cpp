/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:19:35 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/05 11:46:11 by tdutel           ###   ########.fr       */
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
	int	N = len(_tab);
	int	*cpy = new int[N];

	for (int i = 0; i < N; i++)
		cpy[i] = _tab[i];
	std::sort(cpy, cpy + N);

	int i = 0;
	int min = std::min(cpy[i + 1] - cpy[i], cpy[i + 2] - cpy[i + 1]);
	int result = min;
	while (i + 2 < N)
	{
		min = std::min(cpy[i + 1] - cpy[i], cpy[i + 2] - cpy[i + 1]);
		result = std::min(result, min);
		i++;
	}
	delete[] cpy;
	return (result);
}

int		Span::longestSpan()
{
{
	int	N = len(_tab);
	int	*cpy = new int[N];

	for (int i = 0; i < N; i++)
		cpy[i] = _tab[i];
	std::sort(cpy, cpy + N);
	int result = cpy[N - 1] - cpy[0];
	// int i = 0;
	// int max = std::max(cpy[i + 1] - cpy[i], cpy[i + 2] - cpy[i + 1]);
	// int result = max;
	// while (i + 2 < N)
	// {
	// 	max = std::max(cpy[i + 1] - cpy[i], cpy[i + 2] - cpy[i + 1]);
	// 	result = std::max(result, max);
	// 	i++;
	// }
	delete[] cpy;
	return (result);
}
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
