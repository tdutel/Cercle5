/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:31:14 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/15 10:01:35 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "Color.hpp"
# include <iostream>
# include <algorithm>

class notFindException : public std::exception
	{
		public:
			virtual const char* what(void) const throw()
			{
				return ("Not found the occurence.");
			}
	};

template < typename T>
size_t	easyfind(T &ctn, int nb)
{
	typename T::const_iterator it = ctn.begin();
	typename T::const_iterator ite = ctn.end();
	typename T::const_iterator result = std::find(it, ite, nb);

	if (result == ite)
		throw notFindException();
	size_t	i = 0;
	while (it != result)
	{
		it++;
		i++;
	}
	return(i);
}

#endif
