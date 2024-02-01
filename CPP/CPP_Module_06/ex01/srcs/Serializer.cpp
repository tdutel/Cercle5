/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:38:03 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/01 09:33:32 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &cpy)
{
	(void)cpy;
}

Serializer::~Serializer()
{
}

Serializer&	Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

// ---------------------------functions--------------------------- //

uintptr_t	Serializer::serialize(Data* ptr)
{
	std::cout << "serialize function called" << std::endl;
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	std::cout << std::endl << "deserialize function called" << std::endl;
	return(reinterpret_cast<Data*>(raw));
}
