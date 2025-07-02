/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:08:29 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 12:10:52 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//CONSTRUCTORS & DESTRUCTOR

WrongCat::WrongCat()
{
	std::cout << "Default constructor of WrongCat called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& original) : WrongAnimal(original)
{
	std::cout << "Copy constructor of WrongCat called" << std::endl;
	*this = original;
}

WrongCat::~WrongCat()
{
	std::cout << "Default destructor of WrongCat called" << std::endl;
}

//OPERATOR

WrongCat&	WrongCat::operator=(const WrongCat& original)
{
	std::cout << "Copy assignment operator of WrongCat called" << std::endl;
	_type = original._type;
	return (*this);
}

//MEMBER FUNCTIONS

void	WrongCat::makeSound(void) const
{
	std::cout << "Whooo Whoooo Whoooo...." << std::endl;
}
