/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:55:40 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/07 15:12:19 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//CONSTRUCTORS & DESTRUCTOR

Animal::Animal() : _type("Default")
{
	std::cout << _type << " constructor of Animal called" << std::endl;
}

Animal::Animal(const Animal &original)
{
	std::cout << "Copy constructor of Animal " << _type << " called" << std::endl;
	*this = original;
}

Animal::~Animal()
{
	std::cout << "Default destructor of Animal " << _type << " called" << std::endl;
}

//OPERATOR

Animal&	Animal::operator=(const Animal &original)
{
	std::cout << "Copy assignment operator of Animal " << _type << " called" << std::endl;
	if (this != &original)
		_type = original._type;
	return (*this);
}

//GETTER

std::string	Animal::getType() const
{
	return (_type);
}

// MEMBER FUNCTIONS

void	Animal::makeSound() const
{
	std::cout << "A random and irrecognizable sound." << std::endl;
}
