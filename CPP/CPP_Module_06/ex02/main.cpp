/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:15:47 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/30 10:15:01 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"headers/Base.hpp"
#include"headers/A.hpp"
#include"headers/B.hpp"
#include"headers/C.hpp"

#include <iostream>
#include <ctime>

Base	*generate(void)
{
	std::srand(std::time(nullptr));
	int	random = std::rand() % 3;
	Base *p = NULL;
	switch (random)
	{
	case 0:
		p = new A;
		std::cout << "generating an A object" << std::endl;
		break;
	case 1:
		p = new B;
		std::cout << "generating a B object" << std::endl;
		break;
	case 2:
		p = new C;
		std::cout << "generating a C object" << std::endl;
	}
	return (p);
}

void	identify(Base *p)
{
	A	*tmpA;
	tmpA = dynamic_cast<A*>(p);
	if (tmpA != NULL)
	{
		std::cout << "type is A" << std::endl;
		return;
	}
	B	*tmpB = dynamic_cast<B*>(p);
	if (tmpB != NULL)
	{
		std::cout << "type is B" << std::endl;
		return;
	}
	C	*tmpC = dynamic_cast<C*>(p);
	if (tmpC != NULL)
	{
		std::cout << "type is C" << std::endl;
		return;
	}
}

void	identify(Base &p)
{
	try
	{
		A	&tmpA = dynamic_cast<A&>(p);
		std::cout << "type is A" << std::endl;
	}
	catch(std::bad_cast &bc)
	{
	}
	try
	{
		B	&tmpB = dynamic_cast<B&>(p);
		std::cout << "type is B" << std::endl;
	}
	catch(std::bad_cast &bc)
	{
	}
	try
	{
		C	&tmpC = dynamic_cast<C&>(p);
		std::cout << "type is C" << std::endl;
	}
	catch(std::bad_cast &bc)
	{
	}

}

int	main(void)
{
	Base *a = generate();
	identify(a);
	identify(*a);
	delete (a);
}
