/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:02:12 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/24 15:44:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fpNumber;
		static const int	_fractBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator = (const Fixed& original);
		~Fixed();
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
};

#endif
