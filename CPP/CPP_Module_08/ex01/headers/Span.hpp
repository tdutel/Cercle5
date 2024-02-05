/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:15:27 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/05 10:03:50 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>

class Span
{
	public:

// constructor //
	Span(unsigned int N);
	Span(const Span &cpy);
	~Span();

// operator //
Span &operator=(const Span& other);

// functions //
	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	int	getNb(unsigned int n);
	int	*getTab();
	int	len(int *_tab);


	private:

	int	*_tab;

};
#endif
