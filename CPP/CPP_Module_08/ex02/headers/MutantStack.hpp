/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:50:34 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/13 13:53:46 by tdutel           ###   ########.fr       */
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
		this->c = cpy.c;
	}

	MutantStack	&operator=(MutantStack const &other)
	{
		this->c = other.c;
		return (*this);
	}

	~MutantStack(){};
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_ite;
	
	iterator	begin()
	{
		return (this->c.begin());
	}

	iterator	end()
	{
		return (this->c.end());
	}

	iterator	begin()	const
	{
		return (this->c.begin());
	}

	iterator	end()	const
	{
		return (this->c.end());
	}
};

#endif
