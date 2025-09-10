/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isSomething.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:44:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/10 18:08:51 by dicarval         ###   ########.fr       */
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

bool	isDouble(const std::string &input)
{
	std::istringstream iss(input);
	double f;
	char c;
	if (!(iss >> f))
		return false;
	if (iss >> c)
		return false;
	return true;
}

bool	isFloat(const std::string &input)
{
	std::istringstream iss(input);
	float f;
	char c;
	if (!(iss >> f))
		return false;
	if (iss >> c)
		return false;
	return true;
}

bool	isInt(const std::string &input)
{
	long nb;
	if (std::strlen(input.c_str()) > 19)
		throw std::invalid_argument("The integer limits were crossed");
	else if (sscanf(input.c_str(), "%ld", &nb) < 0  || \
		std::strlen(input.c_str()) != longLen(nb))
		return false;
	else if (nb > INT_MAX || nb < INT_MIN)
		throw std::invalid_argument("The integer limits were crossed");
	return true;
}
