/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:24:41 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/25 15:04:52 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//OPERATORS
Fixed&	Fixed::operator=(const Fixed& original)
{
	_fpNumber = original._fpNumber;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

bool	Fixed::operator>(const Fixed& compare)const
{
	if(_fpNumber > compare._fpNumber)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed& compare)const
{
	if(_fpNumber < compare._fpNumber)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed& compare)const
{
	if(_fpNumber >= compare._fpNumber)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed& compare)const
{
	if(_fpNumber <= compare._fpNumber)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed& compare)const
{
	if(_fpNumber == compare._fpNumber)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed& compare)const
{
	if(_fpNumber != compare._fpNumber)
		return (true);
	else
		return (false);
}

float	Fixed::operator+(const Fixed& value)
{
	return((float)(_fpNumber + value._fpNumber) / (1 << _fractBits));
}

float	Fixed::operator-(const Fixed& value)
{
	return((float)(_fpNumber - value._fpNumber) / (1 << _fractBits));
}

float	Fixed::operator*(const Fixed& value)
{
	return ((float)(_fpNumber * value._fpNumber) / (1 << _fractBits * 2));
}

float	Fixed::operator/(const Fixed& value)
{
	return((float)(_fpNumber / value._fpNumber) / (1 << _fractBits));
}

Fixed&	Fixed::operator++()
{
	_fpNumber++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	_fpNumber--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp._fpNumber = _fpNumber;
	_fpNumber++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	temp._fpNumber = _fpNumber;
	_fpNumber--;
	return (temp);
}
