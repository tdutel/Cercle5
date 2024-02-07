/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:31:14 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/07 11:55:18 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template < typename T>
int	easyfind(T &ctn, int nb)
{
	typename T::const_iterator it = ctn.begin();
	typename T::const_iterator ite = ctn.end();
	typename T::const_iterator result = std::find(it, ite, nb);

	if (result == ite)
		throw (std::exception());
	int	i = 0;
	while (it != result)
	{
		it++;
		i++;
	}
	return(i);
}

#endif
