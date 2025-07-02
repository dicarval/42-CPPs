/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:21:27 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 09:21:30 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::getFractionalBits()const
{
	return(_fractBits);
}

int	Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(_fpNumber);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fpNumber = raw;
}

int	Fixed::toInt(void)const
{
	return(_fpNumber >> _fractBits);
}

float	Fixed::toFloat(void)const
{
	return((float)_fpNumber / (1 << _fractBits));
}
