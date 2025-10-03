/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isSomething.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:44:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/03 15:06:30 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

size_t	longLen(long nb)
{
	size_t length = 0;

	if (nb == 0)
		length = 1;
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			++length;
		}
		while (nb > 0)
		{
			nb /= 10;
			++length;
		}
	}
	return length;
}

bool	isSpecial(const std::string &input)
{
	if (input == "-inff" || input == "-inf" || input == "nanf" \
	|| input == "+inff" || input == "+inf" || input == "nan")
		return true;
	return false;
}

bool	isDouble(const std::string &input)
{
	std::istringstream iss(input);
	double d;
	char c;

	if (!(iss >> d) || iss >> c)
		return false;
	else if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
		return false;
	return true;
}

bool	isFloat(const std::string &input)
{
	std::string temp = input;
	float f;
	char c;

	if (!temp.empty() && temp[temp.size() - 1] == 'f')
	{
		temp.erase(temp.size() - 1);
		std::istringstream iss(temp);
		if (!(iss >> f) || iss >> c)
			return false;
		else if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
			return false;
		return true;
	}
	return false;
}

bool	isInt(const std::string &input)
{
	long nb;

	if (!input.find('.') && std::strlen(input.c_str()) > 19)
		throw std::invalid_argument("Error: max digits crossed");
	else if (sscanf(input.c_str(), "%ld", &nb) < 0)
		throw std::invalid_argument("Error: sscanf error");
	else if (std::strlen(input.c_str()) != longLen(nb))
		return false;
	else if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
		return false;
	return true;
}
