/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minnMax.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:12:17 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/25 16:03:53 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed&	Fixed::min(Fixed& value1, Fixed& value2)
{
	if(value1 < value2)
		return (value1);
	return (value2);
}

Fixed&	Fixed::min(const Fixed& value1, const Fixed& value2)
{
	if(value1 < value2)
		return ((Fixed&)value1);
	return ((Fixed&)value2);
}

Fixed&	Fixed::max(Fixed& value1, Fixed& value2)
{
	if(value1 > value2)
		return (value1);
	return (value2);
}

Fixed&	Fixed::max(const Fixed& value1, const Fixed& value2)
{
	if(value1 > value2)
		return ((Fixed&)value1);
	return ((Fixed&)value2);
}
