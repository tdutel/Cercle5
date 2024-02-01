/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:09:52 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/01 09:50:28 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Iter.hpp"

int	main()
{
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	iter(tab, 10, &print);
	std::cout << std::endl;
	char chab[] = "eh yoo welcome to my level";
	iter(chab, 26, &print);

	return (0);
}
