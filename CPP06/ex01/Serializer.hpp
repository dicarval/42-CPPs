/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:06:57 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/15 19:12:16 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

class	Serializer
{
	Serializer();
	Serializer(Serializer &original);
	virtual ~Serializer() = 0;

	uintptr_t	serialize(Data* ptr);
	Data*		deserialize(uintptr_t raw);
};

#endif
