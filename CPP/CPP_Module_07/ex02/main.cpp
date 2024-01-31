/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:58:35 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/31 10:53:34 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Array.hpp"

int	main()
{
	try
	{
		Array<int>	a(10);
		Array<int>	b;
		std::cout << std::endl << "a size : " << a.size() << std::endl;
		std::cout << "b size : " << b.size() << std::endl << std::endl;
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = i;
			// b[b.size() - i - 1] = i;
			std::cout << "a[" << i << "] : " << a[i] << std::endl;
		}
		std::cout << std::endl;
		b = a;
		std::cout << std::endl;
		for (size_t i = 0; i < b.size(); i++)
		{
			std::cout << "b[" << i << "] : " << b[i] << std::endl;
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
