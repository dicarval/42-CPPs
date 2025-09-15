/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:16:32 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/15 15:39:40 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <sstream>

bool	isInt(const std::string &input);
bool	isFloat(const std::string &input);
bool	isDouble(const std::string &input);
bool	isSpecial(const std::string &input);


void	charDisplay(const std::string &input);
void	intDisplay(const std::string &input);
void	floatDisplay(const std::string &input);
void	doubleDisplay(const std::string &input);
void	specialDisplay(const std::string &input);
void	invalidDisplay();

#endif
