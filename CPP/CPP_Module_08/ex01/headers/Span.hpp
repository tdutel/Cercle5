/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:15:27 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/09 15:04:24 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

# include "Color.hpp"

class Span
{
	public:

// constructor //
	Span(unsigned int N);
	Span(const Span &cpy);
	~Span();

	std::vector<int>::iterator	getIt(void);
	std::vector<int>::iterator	getIte(void);
	size_t		getSize();

// operator //
Span &operator=(const Span& other);

// functions //
	void	addNumber(int n);
	void	addNumber(std::vector<int>::iterator itr, size_t size);
	void	addNumber(std::vector<int>::iterator itr, std::vector<int> ve);
	int		shortestSpan();
	int		longestSpan();
	
	class MaxException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};
	class MinException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

	private:
	Span();
	std::vector<int> _tab;
	unsigned	int _max;

};
#endif

// const char* BadExceptiom::what() throw()
// {
// 	return ¨Error¨;
// }
