/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:01:04 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/17 15:41:05 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//CONSTRUCTORS & DESTRUCTOR

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice& original) : AMateria("ice")
{
	*this = original;
}

Ice::~Ice()
{}

//OPERATOR

Ice&	Ice::operator=(const Ice& original)
{
	(void)original;
	return (*this);
}

//MEMBER FUNCTIONS

Ice* Ice::clone() const
{
	Ice* newIce = new Ice(*this);
	return (newIce);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* Shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
