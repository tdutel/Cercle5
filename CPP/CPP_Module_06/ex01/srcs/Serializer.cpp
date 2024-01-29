/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:38:03 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/29 13:50:31 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &cpy)
{
}

Serializer::~Serializer()
{
}

Serializer&	Serializer::operator=(const Serializer &other)
{
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
