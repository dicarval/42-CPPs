/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:22:23 by dicarval          #+#    #+#             */
/*   Updated: 2026/01/14 09:44:40 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	checkChars(const std::string &input)
{
	if (!std::isdigit(input[0]))
		throw RPN::InvalidInput();
	for(unsigned int i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]) && !std::isspace(input[i]) &&\
		std::strchr("+-*/", input[i]) == NULL)
			throw RPN::InvalidInput();
		else if (input.length() == (i + 1) && std::isdigit(input[i]))
			throw RPN::InvalidInput();
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return(std::cout << "Wrong number of arguments" << std::endl, 1);
	try
	{
		std::string input(av[1]);
		checkChars(input);
		RPN rpn;
		rpn.convertToDeque(input);
		rpn.performTheMagic();
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
