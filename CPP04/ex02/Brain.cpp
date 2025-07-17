/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:47:17 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/17 18:08:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//CONSTRUCTORS & DESTRUCTOR

Brain::Brain()
{
	std::cout << "Default constructor of Brain called" << std::endl;
	for(int i = 0; i < 100; ++i)
		_ideas[i] = "Empty slot";
}

Brain::Brain(const Brain& original)
{
	std::cout << "Copy constructor of Brain called" << std::endl;
	*this = original;
}

Brain::~Brain()
{
	std::cout << "Default destructor of Brain called" << std::endl;
}

//OPERATOR

Brain&	Brain::operator=(const Brain& original)
{
	std::cout << "Copy assignment operator of Brain called" << std::endl;
	if (this != &original)
	{
		for (int i = 0; i < 100; ++i)
		_ideas[i] = original._ideas[i];
	}
	return (*this);
}

//SETTER

void	Brain::setIdea(std::string idea, unsigned int index)
{
	if (index < 100)
	{
		_ideas[index] = idea;
		return ;
	}
	std::cout << "Invalid Index" << std::endl;
}

//GETTER

std::string	Brain::getIdea(unsigned int index) const
{
	return(_ideas[index]);
}


//MEMBER FUNCTION

void	Brain::printIdeas(unsigned int first, unsigned int last)
{
	if (first >= 100 || last >= 100)
	{
		std::cout << "Ideas beyond the brain limit" << std::endl;
		return ;
	}
	if (first > last)
	{
		std::cout << "The brain is overheating!!" << std::endl;
		return ;
	}
	for(unsigned int i = first; i <= last; i++)
		std::cout << "Idea[" << i << "] - " <<_ideas[i] << std::endl;
}
