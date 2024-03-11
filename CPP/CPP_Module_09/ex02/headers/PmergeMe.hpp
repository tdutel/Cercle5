/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:52:57 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/11 15:47:17 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <string>
# include <algorithm>

class PmergeMe
{
private:
	std::vector<int>	_vect;
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	int	parseVect(char **argv);
};


#endif
