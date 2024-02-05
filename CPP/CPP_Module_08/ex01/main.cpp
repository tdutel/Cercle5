/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:26:16 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/05 11:48:12 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	for (int i = 0; i < sp.len(sp.getTab() - 1); i++)
		std::cout << "sp[" << i << "] : " << sp.getNb(i) << std::endl;
	std::cout << std::endl << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;
	// for (int i = 0; i < sp.len(sp.getTab()); i++)
	// 	std::cout << "sp[" << i << "] : " << sp.getNb(i) << std::endl;
	// Span spcpy = sp;
	// for (int i = 0; i < spcpy.len(spcpy.getTab()); i++)
	// 	std::cout << "spcpy[" << i << "] : " << spcpy.getNb(i) << std::endl;
return 0;
}

