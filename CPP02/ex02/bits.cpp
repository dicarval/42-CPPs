/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:21:27 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/25 16:39:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::getFractionalBits()const
{
	return(_fractBits);
}

int	Fixed::getRawBits()const
{
	return(_fpNumber);
}

void	Fixed::setRawBits(int const raw)
{
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
