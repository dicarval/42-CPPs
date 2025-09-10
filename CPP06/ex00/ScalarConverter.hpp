/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:39:44 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/10 17:24:44 by dicarval         ###   ########.fr       */
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
