/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimalFixed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:55:40 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 14:40:19 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnimalFixed.hpp"

//CONSTRUCTORS & DESTRUCTOR

AnimalFixed::AnimalFixed() : _type("Default")
{
	std::cout << _type << " constructor of AnimalFixed called" << std::endl;
}

AnimalFixed::AnimalFixed(const AnimalFixed& original)
{
	std::cout << "Copy constructor of AnimalFixed " << _type << " called" << std::endl;
	*this = original;
}

AnimalFixed::~AnimalFixed()
{
	std::cout << "Default destructor of AnimalFixed " << _type << " called" << std::endl;
}

//OPERATOR

AnimalFixed&	AnimalFixed::operator=(const AnimalFixed& original)
{
	std::cout << "Copy assignment operator of AnimalFixed " << _type << " called" << std::endl;
	if (this != &original)
		_type = original._type;
	return (*this);
}

//GETTER

std::string	AnimalFixed::getType() const
{
	return (_type);
}

// MEMBER FUNCTIONS

void	AnimalFixed::makeSound() const
{
	std::cout << "A random and irrecognizable sound." << std::endl;
}
