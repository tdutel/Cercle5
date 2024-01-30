/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:01 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/30 09:44:25 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Serializer.hpp"

int	main(void)
{
	Data	s_data;

	std::cout << "Creating s_data and initialising s_data.a and s_data.str :" << std::endl << std::endl;

	s_data.a = 1.204f;
	s_data.str = "hello";

	std::cout << "s_data :" << std::endl;
	std::cout << "+-----------------------+" << std::endl;
	std::cout << "| data    a :   " << s_data.a << "   |\n| data  str :   " << s_data.str  << "   |\n";
	std::cout << "+-----------------------+" << std::endl << std::endl;

	std::cout << "Creating pointer s_data_cpy and initialising to NULL :" << std::endl << std::endl;
	Data	*s_data_cpy = NULL;
	std::cout << "s_data_cpy : " << s_data_cpy << std::endl << std::endl << std::endl;

	
	uintptr_t	cpy;
	
	cpy = Serializer::serialize(&s_data);
	s_data_cpy = Serializer::deserialize(cpy);

	std::cout << std::endl << std::endl << "Comparing s_data with s_data_cpy :" << std::endl << std::endl;

	std::cout << "s_data :" << std::endl;
	std::cout << "+-----------------------+" << std::endl;
	std::cout << "| data    a :   " << s_data.a << "   |\n| data  str :   " << s_data.str  << "   |\n";
	std::cout << "+-----------------------+" << std::endl << std::endl;

	std::cout << "s_data_cpy :" << std::endl;
	std::cout << "+-----------------------+" << std::endl;
	std::cout << "| data copy   a : " << s_data_cpy->a << " |\n| data copy str : " << s_data_cpy->str  << " |\n";
	std::cout << "+-----------------------+" << std::endl << std::endl;

	return (0);
}
