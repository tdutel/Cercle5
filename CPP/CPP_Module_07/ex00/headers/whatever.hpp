/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:03:12 by tdutel            #+#    #+#             */
/*   Updated: 2024/01/30 12:05:54 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template<typename T>
void	swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
const T	&min(const T &x, const T &y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

template<typename T>
const T	&max(const T &x, const T &y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

#endif
