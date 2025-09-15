/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:07:00 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/15 19:07:35 by dicarval         ###   ########.fr       */
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
