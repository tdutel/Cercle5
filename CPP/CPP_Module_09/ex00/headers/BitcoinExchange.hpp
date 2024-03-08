/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:25:20 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/08 14:39:52 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
// # include <iomanip>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <map>

class BitcoinExchange
{
private:
	std::map<std::string,float> _data;
	std::string	_input;

public:
	BitcoinExchange(std::string input);
	~BitcoinExchange();

	std::map<std::string,float>	initData();
	void						controlMap();
	int							parseData(std::string file);
};

#endif
