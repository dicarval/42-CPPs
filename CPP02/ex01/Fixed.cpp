/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:25:10 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/24 17:23:22 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fpNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value) : _fpNumber(value << _fractBits)
{
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fpNumber(roundf(value * (1 << _fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

//OPERATOR

Fixed&	Fixed::operator = (const Fixed& original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fpNumber = original._fpNumber;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
