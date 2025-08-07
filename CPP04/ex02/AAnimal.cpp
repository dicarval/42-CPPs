/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:55:40 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 14:40:19 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//CONSTRUCTORS & DESTRUCTOR

AAnimal::AAnimal() : _type("Default")
{
	std::cout << _type << " constructor of AAnimal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& original)
{
	std::cout << "Copy constructor of AAnimal " << _type << " called" << std::endl;
	*this = original;
}

AAnimal::~AAnimal()
{
	std::cout << "Default destructor of AAnimal " << _type << " called" << std::endl;
}

//OPERATOR

AAnimal&	AAnimal::operator=(const AAnimal& original)
{
	std::cout << "Copy assignment operator of AAnimal " << _type << " called" << std::endl;
	if (this != &original)
		_type = original._type;
	return (*this);
}

//GETTER

std::string	AAnimal::getType() const
{
	return (_type);
}

// MEMBER FUNCTIONS

void	AAnimal::makeSound() const
{
	std::cout << "A random and irrecognizable sound." << std::endl;
}
