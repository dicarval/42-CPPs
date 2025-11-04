/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:39:40 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/04 09:28:03 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "include.hpp"

//CONSTRUCTORS & DESTRUCTOR
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter &original)
{
	*this = original;
}

//OPERATORS
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &original)
{
	(void)original;
	return *this;
}

//MEMBER FUNCTIONS
void	ScalarConverter::convert(const std::string &input)
{
	try
	{
		if (input.length() == 1 && !isdigit(input[0]))
			charDisplay(input);
		else
		{
			if (isInt(input))
				intDisplay(input);
			else if (isFloat(input))
				floatDisplay(input);
			else if (isDouble(input))
				doubleDisplay(input);
			else if (isSpecial(input))
				specialDisplay(input);
			else
				invalidDisplay();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		exit (5);
	}
}
