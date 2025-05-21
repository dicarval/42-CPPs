/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:20:34 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/21 14:45:01 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void	replaceArgs(std::string& line, const std::string &replaced, const std::string &replacer)
{
	std::string	new_line;
	std::size_t	start = 0, pos;

	while ((pos = line.find(replaced, start)) != std::string::npos)
	{
		new_line += line.substr(start, pos - start);
		new_line += replacer;
		start = pos + replaced.length();
	}
	new_line += line.substr(start);
	line = new_line;
}

int	main(int argc, char* argv[])
{
	if (argc == 4)
	{
		std::ifstream inputFile(argv[1]);
		if(!inputFile)
			return (std::cerr << "It wasn't possible to open the file " << argv[1] << std::endl, 1);
		else
		{
			std::string base_name = argv[1];
			const std::string file_name = base_name + ".replace";
			std::ofstream outputFile(file_name.c_str());
			if (!outputFile)
				return (std::cerr << "Failed to create the file " << file_name << std::endl, 1);
			std::string replaced = argv[2];
			std::string replacer = argv[3];

			std::string line;
			while (std::getline(inputFile, line))
			{
				replaceArgs(line, replaced, replacer);
				outputFile << line << std::endl;
			}
			inputFile.close();
			outputFile.close();
			return (std::cout << "Replace successfully carried out" << std::endl, 0);
		}
	}
	else
		return (std::cerr << "Wrong number of arguments" << std::endl, 1);
}
