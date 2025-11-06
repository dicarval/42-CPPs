/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:06:57 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/06 08:30:37 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

typedef unsigned long uintptr_t;

#include <iostream>
#include "data.hpp"

class	Serializer
{
	private:
		Serializer();
		Serializer(Serializer &original);
		Serializer&	operator=(const Serializer &original);

	public:
		~Serializer();
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
