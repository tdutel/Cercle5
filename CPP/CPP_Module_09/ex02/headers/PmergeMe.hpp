/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:52:57 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/12 13:10:52 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <deque>
# include <string>
# include <algorithm>


class PmergeMe
{

	private:
		std::vector<int>	_vect;
		std::deque<int>		_deque;

	public:
		PmergeMe();
		~PmergeMe();
		int	parse(char **argv);
		void	mergeMe(int argc, char **argv);
	//vector container
		void	mergeSortV(std::vector<int> &vect);
		void	mergeV(std::vector<int> &leftV, std::vector<int> &rightV, std::vector<int> &vect);
	//deque container
		void	mergeSortD(std::deque<int> &deque);
		void	mergeD(std::deque<int> &leftD, std::deque<int> &rightD, std::deque<int> &deque);
};


#endif
