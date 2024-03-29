/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:50:34 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/14 14:01:52 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
# define MUTANSTACK_HPP

# include <stack>
# include <iostream>

# include "Color.hpp"

template < typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack() : std::stack<T>(){};
	MutantStack(MutantStack const &cpy)
	{
		*this = cpy;
		this->c = cpy.c;
	};

	MutantStack	&operator=(MutantStack const &other)
	{
		this->c = other.c;
		return (*this);
	};

	~MutantStack(){};
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	
	iterator	begin()
	{
		return (this->c.begin());
	};

	iterator	end()
	{
		return (this->c.end());
	};

	const_iterator	begin() const
	{
		return (this->c.begin());
	};

	const_iterator	end() const
	{
		return (this->c.end());
	};

	reverse_iterator	rbegin()
	{
		return (this->c.rbegin());
	};

	reverse_iterator	rend()
	{
		return (this->c.rend());
	};
};

#endif
