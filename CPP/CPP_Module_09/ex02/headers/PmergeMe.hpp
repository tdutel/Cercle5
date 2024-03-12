/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:52:57 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/12 12:03:32 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <string>
# include <algorithm>


class PmergeMe
{

	private:
		std::vector<int>	_vect;

	public:
		PmergeMe();
		~PmergeMe();
		int	parseVect(char **argv);
		void	mergeMe(int argc, char **argv);
		void	mergeSort(std::vector<int> &vect);
		void	merge(std::vector<int> &leftV, std::vector<int> &rightV, std::vector<int> &vect);
};


#endif
