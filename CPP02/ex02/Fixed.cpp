/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:25:10 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/25 13:46:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//CONSTRUCTORS
Fixed::Fixed() : _fpNumber(0)
{}

Fixed::Fixed(const Fixed& original)
{
	*this = original;
}

Fixed::Fixed(const int value) : _fpNumber(value << _fractBits)
{}

Fixed::Fixed(const float value) : _fpNumber(roundf(value * (1 << _fractBits)))
{}

//DESTRUCTOR
Fixed::~Fixed()
{}

