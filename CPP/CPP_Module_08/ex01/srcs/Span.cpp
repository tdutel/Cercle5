/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:19:35 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/02 15:41:32 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/Span.hpp"

Span::Span(unsigned int N)
{
	_tab = new	int[N];
}

Span::~Span()
{
	delete[] _tab;
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

int	Span::get_nb(unsigned int n)
{
	return _tab[n];
}
