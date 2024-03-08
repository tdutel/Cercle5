/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:56:03 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/08 13:30:30 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <map>


# include <iomanip>
# include <cstdlib>

std::map<std::string,float> get_data();
// std::map<std::string,std::string> get_input(const char *in);

void	controlMap(std::map<std::string,float> data);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error: wrong numbers of arguments" << std::endl, 1);

	std::ifstream infile;

	infile.open(argv[1]);
	if (!infile.is_open())
		return (std::cout << "Error: unknown file : " << argv[1] << std::endl, 1);

	std::map<std::string,float> data;
	data = get_data();

	// std::map<std::string, std::string>	input;
	// input = get_input(argv[1]);
	
	controlMap(data);

// 	for(std::map<std::string,std::string>::iterator it = input.begin();
//     it != input.end(); ++it)
// {
// 	std::cout << "input[" << it->first << "] = " << it->second << " " << "\n";
// }
	return (0);
}


std::map<std::string,float> get_data()	// file = 2011-04-08,0.78\n2011-04-11,0.76\n2011-04-14,0.99\0
{
	std::ifstream dtfile;
	std::string file;
	std::map<std::string,float> data;

	dtfile.open("srcs/data.csv");

	while (std::getline(dtfile, file, '\n'))
	{
		// std::cout << file << std::endl;
		float elem;

		elem = std::atof(file.substr(file.find(',') + 1, '\n').c_str());
		data[file.substr(0, file.find(','))] = elem;
		// file = file.substr(file.find('\n') + 1, file.find('\0'));
	}
	dtfile.close();
	return (data);
}



// std::map<std::string,std::string> get_input(const char *in)
// {
// 	std::ifstream dtfile;
// 	std::string file;
// 	std::map<std::string,std::string> data;

// 	dtfile.open(in);

// 	while (std::getline(dtfile, file, '\n'))
// 	{
// 		// std::cout << file << std::endl;
// 		std::string elem;
// 		size_t pos;
// 		pos = file.find('|') + 1;
// 		if (file.find('|') != std::string::npos)
// 			elem = file.substr(pos, '\n');
// 		else
// 			elem = "";
// 		std::string index = min(file.substr(0, file.find(' ')),file.substr(0, file.find('|')));
// 		// std::map<std::string, std::string>::iterator it = data.find(index);
// 		while (data.find(index) != data.end())
// 		{
// 			index.append(" ");
// 		}
// 		data[index] = elem;
// 		file = file.substr(file.find('\n') + 1, file.find('\0'));
// 		std::cout << "file: " << file << std::endl;
// 	}
// 	dtfile.close();
// 	return (data);
// }

//	j'ai reussi a mettre toute la data.csv dans une map avec la date pour first et le ratio pour second.
//	todo: faire le clcul de multiplication avec le input et trouver les elements a la bonne date.

int	parseDate(std::string file);

void	controlMap(std::map<std::string,float> data)
{
	(void)data;
	std::ifstream	infile;
	std::string file;
	infile.open("input.txt");
	std::getline(infile, file, '\n');
	
	while (std::getline(infile, file, '\n'))	//file = "2011-01-03 | 3\n"
	{
		if (parseDate(file) != -1)
		{
			
		}
	}
}

int	parseDate(std::string file)	//	file = "2011-01-03 | 3\n"
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
	
	// std::cout << date << std::endl;
	return 0;
}















	// std::map<std::string, std::string>::iterator it = input.begin();
		// parseDate(it, input, data);
		// // std::cout << "next" << std::endl;
		// std::cout << "it second: " << it->second << std::endl;
		// it++;


// int	parseDate(std::map<std::string, std::string>::iterator it, std::map<std::string, std::string> input, std::map<std::string, float> data)
// {
// 	(void) input;
// 	// if (it->first < "2009-01-02")
// 	// {
// 	// 	while(it->first )
// 	// }
// 		// it->first = "2009-01-02";	//assigner a la valeur la plus proche
// 	if (it->second >= "2147483648")
// 		return (std::cout << "Error: too large a number." << std::endl, 1);
// 	if (std::atof(it->second.c_str()) < 0)
// 		return (std::cout << "Error: not a positive number.\n", 1);
// 	if (it->second == "")
// 		return (std::cout << "Error: bad input => " << it->first << std::endl, 1);
// 	std::map<std::string, float>::iterator dte = data.end();
// 	float	result;
// 	dte--;
// 	while(dte->first > it->first)
// 		dte--;
// 	result = std::atof(it->second.c_str()) * dte->second;
// 	std::cout << it->first << " => " << it->second << " = " << result << std::endl;
// 	return (0);
// }
	//	todo:
//		not a positive number.
//		bad input => 2001-42-42
//		too large a number
