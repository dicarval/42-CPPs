/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaySomething.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:37:46 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/10 17:44:47 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	floatDisplay(const std::string &input)
{
	std::istringstream iss(input);
	float f;
	iss >> f;
	std::cout << "char: ";
	int i = static_cast<int>(f);
	if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: "  << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	intDisplay(const std::string &input)
{
	int i;

	if (sscanf(input.c_str(), "%d", &i) < 0)
		throw std::invalid_argument("sscanf error");
	std::cout << "char: ";
	if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: "  << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void	charDisplay(const std::string &input)
{
	char c = static_cast<char>(input[0]);
	int i = static_cast<int>(input[0]);
	float f = static_cast<float>(input[0]);
	double d = static_cast<double>(input[0]);

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: "  << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
