/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:02:12 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/24 17:24:36 by dicarval         ###   ########.fr       */
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
		Fixed(const Fixed& copy);
		Fixed& operator = (const Fixed& original);
		~Fixed();
		int				getRawBits(void)const;
		int				getFractionalBits()const;
		void			setRawBits(int const raw);
		float			toFloat(void)const;
		int				toInt(void)const;
};

#endif
