/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:15:27 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/02 15:39:35 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span
{
	public:

// constructor //
	Span(unsigned int N);
	~Span();

// functions //
	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	int	get_nb(unsigned int n);


	private:

	int	*_tab;

};
#endif
