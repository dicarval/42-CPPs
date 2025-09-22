/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:59:52 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/22 17:35:42 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int	_len;
		T*				_array;

	public:
		Array();
		Array(unsigned int n);
		Array(Array &original);
		~Array();

		Array&			operator=(const Array &original);
		T& 				operator[](unsigned int index);

		unsigned int	size() const;
		void			iter( void (*func)(T&));
};

#include "Array.tpp"

#endif
