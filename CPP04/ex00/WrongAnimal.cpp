/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:44:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 12:00:39 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//CONSTRUCTORS & DESTRUCTOR

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "Default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
	*this = original;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default destructor of WrongAnimal called" << std::endl;
}

//OPERATOR

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& original)
{
	std::cout << "Copy assignment operator of WrongAnimal called" << std::endl;
	_type = original._type;
	return (*this);
}

// GETTERS

std::string	WrongAnimal::getType() const
{
	return (_type);
}

//MEMBER FUNCTIONS

void	WrongAnimal::makeSound(void) const
{
	std::cout << "BAHAHAHAHHAHAHAHHA" << std::endl;
}
