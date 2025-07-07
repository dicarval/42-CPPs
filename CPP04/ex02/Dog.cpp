/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:44:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/04 11:14:56 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//CONSTRUCTORS & DESTRUCTOR

Dog::Dog() : AnimalFixed()
{
	std::cout << "Default constructor of Dog called" << std::endl;
	_type = "Dog";
	_processor = new Brain();
}

Dog::Dog(const Dog& original) : AnimalFixed(original)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	*this = original;
}

Dog::~Dog()
{
	std::cout << "Default destructor of Dog called" << std::endl;
	delete _processor;
}

//OPERATOR

Dog&	Dog::operator=(const Dog& original)
{
	std::cout << "Copy assignment operator of Dog called" << std::endl;
	if (this != &original)
	{
		_type = original._type;
		_processor = new Brain(*original._processor);
	}
	return (*this);
}

//SETTER

void	Dog::setDogIdea(std::string idea, unsigned int index)
{
	_processor->setIdea(idea, index);
}

//GETTER

std::string	Dog::getDogIdea(unsigned int index) const
{
	return (_processor->getIdea(index));
}

Brain*	Dog::getDogBrain(void) const
{
	return (_processor);
}

//MEMBER FUNCTIONS

void	Dog::makeSound(void) const
{
	std::cout << "Wooff?" << std::endl;
}

void	Dog::printDogIdeas(unsigned int first, unsigned int last)
{
	_processor->printIdeas(first, last);
}
