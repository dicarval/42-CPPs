/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaySomething.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:37:46 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/04 14:03:42 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	charConvert(const long &i)
{
	std::cout << "char: ";
	if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(i) << std::endl;
}

void intConvert(const long &i)
{
	std::cout << "int: ";
	if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(i) << std::endl;
}

void	invalidDisplay()
{
	std::cout << "NOP!" << std::endl;
}

void	specialDisplay(const std::string &input)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(strtof(input.c_str(), NULL)) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(strtod(input.c_str(), NULL)) << std::endl;
}

void	doubleDisplay(const std::string &input)
{
	std::istringstream iss(input);
	double d;
	iss >> d;
	long i = static_cast<long>(d);

	charConvert(i);

	intConvert(i);

	std::cout << std::fixed << std::setprecision(1);
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: "  << static_cast<float>(d) << "f" << std::endl;

	std::cout << "double: " << d << std::endl;
}

void	floatDisplay(const std::string &input)
{
	std::istringstream iss(input);
	float f;
	iss >> f;
	long i = static_cast<long>(f);

	charConvert(i);

	intConvert(i);

	std::cout << std::fixed << std::setprecision(1);
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: "  << f << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	intDisplay(const std::string &input)
{
	int i;

	if (sscanf(input.c_str(), "%d", &i) < 0)
		throw std::invalid_argument("Error: sscanf error");

	charConvert(i);

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
