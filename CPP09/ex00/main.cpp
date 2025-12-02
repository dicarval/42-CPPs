/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:00:10 by dicarval          #+#    #+#             */
/*   Updated: 2025/12/02 10:41:55 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string	intToDateFormat(int number)
{
	std::ostringstream oss;

	if (number < 10)
		oss << "0" << number;
	else
		oss << number;
	return (oss.str());

}

bool	isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Wrong number of arguments" << std::endl, 1);
	try
	{
		BitcoinExchange btc;
		std::string input(av[1]);
		btc.loadInput(input);
		btc.printExchangeResults();
	}
	catch(const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
