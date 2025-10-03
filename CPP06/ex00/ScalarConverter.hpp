/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:39:44 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/03 15:06:41 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class	ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter &original);
		virtual ~ScalarConverter() = 0;

		ScalarConverter& operator=(const ScalarConverter &original);

		static void convert(const std::string &input);
};


#endif
