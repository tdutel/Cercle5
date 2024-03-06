/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:56:03 by tdutel            #+#    #+#             */
/*   Updated: 2024/03/06 15:59:42 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <map>


# include <iomanip>
# include <cstdlib>

std::map<std::string,float> get_data(std::string file);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error: wrong numbers of arguments" << std::endl, 1);
	std::ifstream infile;

	infile.open(argv[1]);
	if (!infile.is_open())
		return (std::cout << "Error: unknown file : " << argv[1] << std::endl, 1);

	std::map<std::string,float> data;
	std::string file;
	std::getline(infile, file, '\0');

	data = get_data(file);

	for(std::map<std::string,float>::iterator it = data.begin();
    it != data.end(); ++it)
{
    std::cout << "data[" << it->first << "] = " << it->second << " " << "\n";
}
	return (0);
}

std::map<std::string,float> get_data(std::string file)	// file = 2011-04-08,0.78\n2011-04-11,0.76\n2011-04-14,0.99\0
{
	std::string str;
	std::map<std::string,float> data;
	// std::string nb;

	while (file.size() > 0)
	{
		// std::cout << "file : \n"<< file << std::endl;
		str = file.substr(0, file.find('\n'));
		// std::cout << "str: \n"<< str << std::endl << std::endl;
		data[str.substr(0, str.find(','))] = std::atof(str.substr(str.find(','), '\n').c_str());
		file = file.substr(file.find('\n') + 1, file.find('\0'));
	}
	return (data);
}

//	j'ai reussi a mettre toute la data.csv dans une map avec la date pour first et le ratio pour second.
//	todo: faire le clcul de multiplication avec le input et trouver les elements a la bonne date.
