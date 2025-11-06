/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:39:44 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/06 08:28:08 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &original);
		ScalarConverter& operator=(const ScalarConverter &original);

	public:
		~ScalarConverter();
		static void convert(const std::string &input);
};


#endif
