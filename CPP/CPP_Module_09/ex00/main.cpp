/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:56:03 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/07 14:10:10 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <map>


# include <iomanip>
# include <cstdlib>

std::map<std::string,std::string> get_data(std::string file);
std::map<std::string,std::string> get_input(const char *in);

// void	controlMap(std::string	input, std::map<std::string,float> data);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error: wrong numbers of arguments" << std::endl, 1);

	std::ifstream infile;

	infile.open(argv[1]);
	if (!infile.is_open())
		return (std::cout << "Error: unknown file : " << argv[1] << std::endl, 1);

	std::map<std::string,std::string> data;
	data = get_data("srcs/data.csv");

	std::map<std::string, std::string>	input;
	input = get_input(argv[1]);
	
	// controlMap(input, data);

	for(std::map<std::string,std::string>::iterator it = input.begin();
    it != input.end(); ++it)
{
	std::cout << "input[" << it->first << "] = " << it->second << " " << "\n";
}
	return (0);
}


std::map<std::string,std::string> get_data(std::string in)	// file = 2011-04-08,0.78\n2011-04-11,0.76\n2011-04-14,0.99\0
{
	std::ifstream dtfile;
	std::string file;
	std::map<std::string,std::string> data;

	dtfile.open(in.c_str());

	while (std::getline(dtfile, file, '\n'))
	{
		std::cout << file << std::endl;
		std::string elem;
		size_t pos;
		pos = file.find(',') + 1;
		if (file.find(',') != std::string::npos)
			elem = file.substr(pos, '\n');
		else
			elem = "";
		data[file.substr(0, file.find(','))] = elem;
		file = file.substr(file.find('\n') + 1, file.find('\0'));
	}
	dtfile.close();
	return (data);
}



std::map<std::string,std::string> get_input(const char *in)
{
	std::ifstream dtfile;
	std::string file;
	std::map<std::string,std::string> data;

	dtfile.open(in);

	while (std::getline(dtfile, file, '\n'))
	{
		std::cout << file << std::endl;
		std::string elem;
		size_t pos;
		pos = file.find('|') + 1;
		if (file.find('|') != std::string::npos)
			elem = file.substr(pos, '\n');
		else
			elem = "";
		std::map<std::string, std::string>::iterator it = data.find(file.substr(0, file.find(' ')));
		if (it == data.end())
			data[file.substr(0, file.find(' '))] = elem;
		else
			data[file.substr(0, file.find(' ') + 1)] = elem;
		file = file.substr(file.find('\n') + 1, file.find('\0'));
	}
	dtfile.close();
	return (data);
}

//	j'ai reussi a mettre toute la data.csv dans une map avec la date pour first et le ratio pour second.
//	todo: faire le clcul de multiplication avec le input et trouver les elements a la bonne date.


// void	controlMap(std::string input, std::map<std::string,float> data)
// {
// 	std::map<std::string,float>::iterator it = data.find(input);
// 	if (it != data.end())
// 	{}
// }
	// std::string	input;
	// std::getline(infile, input, '\0');


// std::map<std::string,float> get_input(char *in)
// {
// 	std::ifstream infile;
// 	std::string input;
	
// 	infile.open(in);
// 	std::getline(infile, input, '\0');
// 	infile.close();

// 	std::string str;
// 	std::map<std::string,float> data;

// 	while (input.size() > 0)
// 	{
// 		str = input.substr(0, input.find('\n'));
// 		data[str.substr(0, str.find('|'))] = std::atof(str.substr(str.find('|'), '\n').c_str());
// 		input = input.substr(input.find('\n') + 1, input.find('\0'));
// 	}
// 	return (data);
// }
