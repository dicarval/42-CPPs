/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:44:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 17:07:00 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//CONSTRUCTORS & DESTRUCTOR

Dog::Dog() : Animal()
{
	std::cout << "Default constructor of Dog called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& original) : Animal(original)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	*this = original;
}

Dog::~Dog()
{
	std::cout << "Default destructor of Dog called" << std::endl;
}

//OPERATOR

Dog&	Dog::operator=(const Dog& original)
{
	std::cout << "Copy assignment operator of Dog called" << std::endl;
	_type = original._type;
	return (*this);
}

//MEMBER FUNCTIONS

void	Dog::makeSound(void) const
{
	std::cout << "Wooff?" << std::endl;
}
