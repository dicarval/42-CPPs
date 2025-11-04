/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:07:00 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/04 10:40:19 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//CONSTRUCTORS & DESTRUCTOR
Serializer::Serializer()
{}

Serializer::Serializer(Serializer &original)
{
	*this = original;
}

//OPERATORS
Serializer&	Serializer::operator=(const Serializer &original)
{
	(void)original;
	return *this;
}

//MEMBER FUNCTIONS
uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
