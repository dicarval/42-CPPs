/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:16:26 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/17 18:08:51 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//CONSTRUCTORS & DESTRUCTOR

AMateria::AMateria() : _type("Unknow")
{}

AMateria::AMateria(const std::string& type) : _type(type)
{}

AMateria::AMateria(const AMateria& original)
{
	*this = original;
}

AMateria::~AMateria()
{}

//OPERATOR

AMateria&	AMateria::operator=(const AMateria& original)
{
	if (this != &original)
		_type = original._type;
	return (*this);
}

//GETTER

const std::string&	AMateria::getType() const
{
	return(_type);
}

//MEMBER FUNCTIONS

void	AMateria::use(ICharacter& target)
{
	std::cout << "* Something unknow was thrown at " << target.getName() << " *" << std::endl;
}
