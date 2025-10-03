/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:33:41 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/03 15:06:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string input = av[1];
		ScalarConverter::convert(input);
	}
	else
		return (std::cout << "Wrong number of arguments" << std::endl, 5);
}
