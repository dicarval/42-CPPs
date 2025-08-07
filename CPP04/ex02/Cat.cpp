/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:08:29 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/04 11:14:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//CONSTRUCTORS & DESTRUCTOR

Cat::Cat() : AAnimal(), _processor(NULL)
{
	std::cout << "Default constructor of Cat called" << std::endl;
	_type = "Cat";
	_processor = new Brain();
}

Cat::Cat(const Cat& original) : AAnimal(original), _processor(NULL)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
	*this = original;
}

Cat::~Cat()
{
	std::cout << "Default destructor of Cat called" << std::endl;
	delete _processor;
}

//OPERATOR

Cat&	Cat::operator=(const Cat& original)
{
	std::cout << "Copy assignment operator of Cat called" << std::endl;
	if (this != &original)
	{
		_type = original._type;
		if (_processor)
			delete _processor;
		_processor = new Brain(*original._processor);
	}
	return (*this);
}

//SETTER

void	Cat::setCatIdea(std::string idea, unsigned int index)
{
	_processor->setIdea(idea, index);
}

//GETTER

std::string	Cat::getCatIdea(unsigned int index) const
{
	return (_processor->getIdea(index));
}

Brain*	Cat::getCatBrain(void) const
{
	return (_processor);
}

//MEMBER FUNCTIONS

void	Cat::makeSound(void) const
{
	std::cout << "MEOOOWWW!!!" << std::endl;
}

void	Cat::printCatIdeas(unsigned int first, unsigned int last)
{
	_processor->printIdeas(first, last);
}
