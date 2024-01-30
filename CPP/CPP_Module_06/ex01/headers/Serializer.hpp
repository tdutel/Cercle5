/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:37:53 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/30 09:42:37 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include "Data.hpp"
# include <iostream>

class Serializer
{
private:
	Serializer(const Serializer &cpy);
	Serializer	&operator=(const Serializer &other);
	Serializer(void);

public:
	virtual ~Serializer(void);
	static	uintptr_t	serialize(Data* ptr);
	static	Data*	deserialize(uintptr_t raw);
};


#endif
