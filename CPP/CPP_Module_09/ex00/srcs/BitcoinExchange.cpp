/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:45 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/08 15:11:36 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input) : _input(input)
{
	_data = initData();
};

BitcoinExchange::~BitcoinExchange()
{
};

std::map<std::string,float> BitcoinExchange::initData()
{
	std::ifstream dtfile;
	std::string file;
	std::map<std::string,float> data;

	dtfile.open("srcs/data.csv");

	while (std::getline(dtfile, file, '\n'))
	{
		float elem;

		elem = std::atof(file.substr(file.find(',') + 1, '\n').c_str());
		data[file.substr(0, file.find(','))] = elem;
	}
	dtfile.close();
	return (data);
};

void	BitcoinExchange::controlMap()
{
	std::ifstream	infile(this->_input.c_str());
	std::string file;
	std::getline(infile, file, '\n');
	
	while (std::getline(infile, file, '\n'))
	{
		if (parseData(file) != -1)
		{
			std::string date = file.substr(0, 10);
			std::string value = file.substr(13, '\n');
			std::map<std::string,float>::iterator it = this->_data.end();
			it--;
			while(it->first > date)
				it--;
			float result = std::atof(value.c_str()) * it->second;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	}
}

int	BitcoinExchange::parseData(std::string file)
{
	std::string date = file.substr(0, 10);
	if (date < "2009-01-02" || date > "2022-03-29" )
		return (std::cout << "Error: bad input => " << date << std::endl, -1);
	
	std::string month = file.substr(5, 2);
	if (month < "01" || month > "12")
		return (std::cout << "Error: bad input => " << date << std::endl, -1);

	std::string day = file.substr(8, 2);
	if ((day < "01") || (day > "31") || ((day > "30") && (month == "02" || month == "04" || month == "06" || month == "09" || month == "11" )))
		return (std::cout << "Error: bad input => " << date << std::endl, -1);

	std::string year = file.substr(0, 4);
	if (month == "02" && day > "28")
	{
		if (day == "29" && (std::atoi(year.c_str()) % 4 == 0 && std::atoi(year.c_str()) % 100 != 0))
			;
		else
			return (std::cout << "Error: bad input => " << date << std::endl, -1);
	}

	size_t pos = file.find('|');
	if (pos == std::string::npos)
		return (std::cout << "Error: bad input => " << date << std::endl, -1);

	std::string value = file.substr(13, '\n');
	if (std::atol(value.c_str()) < 0)
		return (std::cout << "Error: not a positive number."<< std::endl, -1);

	if (std::atol(value.c_str()) > 1000)
		return (std::cout << "Error: too large a number."<< std::endl, -1);
	return (0);
}
