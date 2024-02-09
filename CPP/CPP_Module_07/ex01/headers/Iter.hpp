/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:09:22 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/09 12:15:53 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T, typename U, typename V>
void	iter(T *tab, U len, V (*f)(T&))
{
	for (U i = 0; i < len; ++i)
	{
		std::cout << "tab[" << i << "] : ";
		f(tab[i]);
	}
};

template <typename T, typename U, typename V>
void	iter(const T *tab, const U len, V (*f)(const T&))
{
	for (U i = 0; i < len; ++i)
	{
		std::cout << "tab[" << i << "] : ";
		f(tab[i]);
	}
};

#endif
