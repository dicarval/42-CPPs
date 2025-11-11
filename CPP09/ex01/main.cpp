/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:22:23 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/11 16:43:50 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	checkInput(const std::string &input)
{
	for(int i = 0; i < input.length(); i++)
	{
		if ((input[i] > '9' && input[i] < '0') || \
		(input[i] != '+' || input[i] != '-' || input[i] != '*' || input[i] != '/'))
				throw invalidInput
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return(std::cout << "Wrong number of arguments" << std::endl, 1);
	try
	{
		std::string input(av[1]);
		checkInput(input);
	}
	catch(const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
