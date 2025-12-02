/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:00:18 by dicarval          #+#    #+#             */
/*   Updated: 2025/12/02 11:30:14 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

void	checkInput(const std::vector<std::string> &input)
{
	if (input.size() > 10000)
		throw PmergeME::InvalidInput();
	for (std::vector<std::string>::const_iterator it = input.begin(); it != input.end(); it++)
	{
		for(unsigned int i = 0; i < (*it).length(); i++)
		{
			if (!std::isdigit((*it)[i]))
				throw PmergeME::InvalidInput();
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (std::cerr << "Program was launched without input" << std::endl, 1);
	try
	{
		std::vector<std::string> input(av + 1, av + ac);
		checkInput(input);
		PmergeME mergeInsert;
		mergeInsert.converterToContainer(input);
		mergeInsert.algoExec();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}
