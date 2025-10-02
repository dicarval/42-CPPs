/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:02:12 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/02 18:21:09 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fpNumber;
		static const int	_fractBits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& original);
		~Fixed();
		int				getRawBits(void)const;
		int				getFractionalBits()const;
		void			setRawBits(int const raw);
		float			toFloat(void)const;
		int				toInt(void)const;

		static Fixed&	min(Fixed& value1, Fixed& value2);
		static Fixed&	min(const Fixed& value1, const Fixed& value2);
		static Fixed&	max(Fixed& value1, Fixed& value2);
		static Fixed&	max(const Fixed& value1, const Fixed& value2);

		Fixed&			operator=(const Fixed& original);

		bool			operator>(const Fixed& compare)const;
		bool			operator<(const Fixed& compare)const;
		bool			operator>=(const Fixed& compare)const;
		bool			operator<=(const Fixed& compare)const;
		bool			operator==(const Fixed& compare)const;
		bool			operator!=(const Fixed& compare)const;

		Fixed			operator+(const Fixed& value);
		Fixed			operator-(const Fixed& value);
		Fixed			operator*(const Fixed& value);
		Fixed			operator/(const Fixed& value);

		Fixed&			operator++();
		Fixed&			operator--();
		Fixed			operator++(int);
		Fixed			operator--(int);

};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif
