/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:08:29 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/07 15:14:03 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//CONSTRUCTORS & DESTRUCTOR

Cat::Cat() : Animal()
{
	std::cout << "Default constructor of Cat called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &original) : Animal(original)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
	*this = original;
}

Cat::~Cat()
{
	std::cout << "Default destructor of Cat called" << std::endl;
}

//OPERATOR

Cat&	Cat::operator=(const Cat &original)
{
	std::cout << "Copy assignment operator of Cat called" << std::endl;
	if (this != &original)
		_type = original._type;
	return (*this);
}

//MEMBER FUNCTIONS

void	Cat::makeSound(void) const
{
	std::cout << "MEOOOOOW!!!" << std::endl;
}
