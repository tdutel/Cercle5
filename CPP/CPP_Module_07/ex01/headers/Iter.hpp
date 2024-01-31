/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:09:22 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/31 13:26:24 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	print(T x)
{
	std::cout << *x << std::endl;
};

template <typename T>
void	iter(T &tab, unsigned int len, void(*print)(T x))
{
	for (size_t i = 0; i < len; i++)
	{
		std::cout << "tab[" << i << "] : ";
		print(&tab[i]);
	}
};

#endif
