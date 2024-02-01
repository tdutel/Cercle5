/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:59:19 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/01 10:08:12 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
	T				*_tab;
	unsigned int	_size;

public:

// constructor //

	Array(void) : _size(0)
	{
		this->_tab = new T();
		std::cout << "\x1b[33mConstructor called\033[0m" << std::endl;
	};

	Array(const Array &cpy) : _size(cpy._size)
	{
		if (this->_size != 0)
		{
			this->_tab = new T[this->_size];
				for (size_t i = 0; i != this->_size; i++)
					this->_tab[i] = cpy._tab[i];
			std::cout << "\x1b[33mCopy Constructor called\033[0m" << std::endl;
		}
	};

	Array(unsigned int n) : _size(n)
	{
		if (this->_size == 0)
			this->_tab = NULL;
		else
		{

			this->_tab = new T[n];
			for (size_t i = 0; i != this->_size; i++)
					this->_tab[i] = T();
		}
		std::cout << "\x1b[33mConstructor Parametric called\033[0m" << std::endl;
	};

	~Array()
	{
		delete[] this->_tab;
		std::cout << "\x1b[33mDestructor called\033[0m" << std::endl;
	};

// operator //

	Array &operator=(const Array& other)
{
	if (this->_size > 0)
		delete[] this->_tab;
	else
		delete this->_tab;
	this->_size = other._size;
	this->_tab = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++)
		this->_tab[i] = other._tab[i];
	std::cout << "\x1b[33mCopy assignment operator called\033[0m" << std::endl;
	return (*this);
}

	T	&operator[](const unsigned int i)
	{
		if (i >= this->_size)
			throw std::exception();
		return (this->_tab[i]);
	}

// functions //
	unsigned int	size(void)
	{
		return (this->_size);
	};
	
};

#endif
