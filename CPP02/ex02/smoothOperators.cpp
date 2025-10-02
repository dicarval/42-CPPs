/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smoothOperators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:24:41 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/02 18:35:07 by dicarval         ###   ########.fr       */
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

Fixed	Fixed::operator+(const Fixed& value)
{
	return(Fixed(this->toFloat() + value.toFloat()));
}

Fixed		Fixed::operator-(const Fixed& value)
{
	return(Fixed(this->toFloat() - value.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& value)
{
	return(Fixed(this->toFloat() * value.toFloat()));;
}

Fixed	Fixed::operator/(const Fixed& value)
{
	return(Fixed(this->toFloat() / value.toFloat()));
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
