/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:06:57 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/04 10:40:29 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

typedef unsigned long uintptr_t;

#include <iostream>
#include "data.hpp"

class	Serializer
{
	public:
		Serializer();
		Serializer(Serializer &original);
		virtual ~Serializer() = 0;

		Serializer&	operator=(const Serializer &original);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
