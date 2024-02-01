/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:31:14 by tdutel            #+#    #+#             */
/*   Updated: 2024/02/01 15:32:32 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

template < typename T>
void easyfind(T &ctn, int nb)
{
	typename T::const_iterator it = ctn.begin();
	typename T::const_iterator ite = ctn.end();
	typename T::const_iterator result = std::find(it, ite, nb);
	std::cout << *result << std::endl;

}

#endif
