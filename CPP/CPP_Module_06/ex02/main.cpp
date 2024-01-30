/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:15:47 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/30 09:38:24 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"headers/Base.hpp"
#include"headers/A.hpp"
#include"headers/B.hpp"
#include"headers/C.hpp"
#include <ctime>

#include <iostream>

Base	*generate(void)
{
	std::srand(std::time(nullptr));
	int	random = std::rand() % 3;
	Base *p = NULL;
	switch (random)
	{
	case 0:
		p = new A;
		std::cout << "A ";
		break;
	case 1:
		p = new B;
		std::cout << "B ";
		break;
	case 2:
		p = new C;
		std::cout << "C ";
	}
	return (p);
}

void	identify(Base *p)
{
	std::cout << p << std::endl;
}

int	main(void)
{
	Base *a = generate();
	identify(a);
	delete (a);
}
