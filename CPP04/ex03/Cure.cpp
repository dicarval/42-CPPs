/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:44:12 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/07 15:05:02 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//CONSTRUCTORS & DESTRUCTOR

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure& original) : AMateria("cure")
{
	*this = original;
}

Cure::~Cure()
{}

//OPERATOR

Cure&	Cure::operator=(const Cure &original)
{
	(void)original;
	return (*this);
}

//MEMBER FUNCTIONS

Cure* Cure::clone() const
{
	Cure	*newCure = new Cure(*this);
	return (newCure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* Heals " << target.getName() << "'s wounds *" << std::endl;
}
