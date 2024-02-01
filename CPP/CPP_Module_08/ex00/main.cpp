/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:32:29 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/01 15:31:26 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/easyfind.hpp"

int	main(void)
{
	// int a[] = { 5, 6, 1, 10, 2, 10};
	// std::vector<int> vect(a, a + 6);
	std::vector<int> vect = {1, 4, 3, 8, 5};
	easyfind(vect, 4);
	const std::vector<int> b = {1, 4, 3, 8, 5};
	easyfind(b,4);
}
