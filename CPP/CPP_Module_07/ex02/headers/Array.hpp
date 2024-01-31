/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:59:19 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/31 10:52:02 by tdutel           ###   ########.fr       */
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
		std::cout << "Constructor called" << std::endl;
	};

	Array(const Array &cpy) : _size(cpy._size)
	{
		if (this->_size != 0)
		{
			this->_tab = new T[this->_size];
				for (size_t i = 0; i != this->_size; i++)
					this->_tab[i] = cpy._tab[i];
			std::cout << "Copy Constructor called" << std::endl;
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
		std::cout << "Constructor Parametric called" << std::endl;
	};

	~Array()
	{
		delete[] this->_tab;
		std::cout << "Destructor called" << std::endl;
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
	{
		this->_tab[i] = other._tab[i];
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

	T	&operator[](const unsigned int i)
	{
		if (i >= this->_size)
		{
			throw std::exception();
		}
		return (this->_tab[i]);
	}

// functions //
	unsigned int	size(void)
	{
		return (this->_size);
	};
	
};

#endif
