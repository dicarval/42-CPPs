/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:00:52 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/06 16:31:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//CONSTRUCTORS & DESTRUCTOR
Span::Span(const unsigned int &nb) : _N(nb)
{}

Span::Span(const Span &original) : _N(original._N)
{}

Span::~Span()
{}

//OPERATORS
Span&	Span::operator=(const Span &original)
{
	if (this != &original)
	{
		if (original._theVector.size() > _N)
			throw std::length_error("Span::operator= : source has more elements than destination capacity");
		_theVector = original._theVector;
	}
	return *this;
}

//MEMBER FUNCTIONS
void	Span::addNumber(const int &newNb)
{
	if (_theVector.size() == _N)
		throw std::length_error("Span::addNumber : Span list is full, no more numbers can be added");
	_theVector.push_back(newNb);
}

unsigned int	Span::shortestSpan()
{
	if (_theVector.size() <= 1)
		throw std::length_error("Span::shortestSpan : No span can be found");
	unsigned int span = UINT_MAX;
	for (unsigned int iter = 0; iter < _theVector.size(); iter++)
	{
		for (unsigned int i = iter + 1; i < _theVector.size(); i++)
		{
			unsigned int diff = (_theVector[iter] > _theVector[i]) ? (_theVector[iter] - _theVector[i]) : (_theVector[i] - _theVector[iter]);
			if (diff < span)
				span = diff;
		}
	}
	return span;
}

unsigned int	Span::longestSpan()
{
	if (_theVector.size() <= 1)
		throw std::length_error("Span::shortestSpan : No span can be found");
	unsigned int span = 0;
	for (unsigned int iter = 0; iter < _theVector.size(); iter++)
	{
		for (unsigned int i = iter + 1; i < _theVector.size(); i++)
		{
			unsigned int diff = (_theVector[iter] > _theVector[i]) ? (_theVector[iter] - _theVector[i]) : (_theVector[i] - _theVector[iter]);
			if (diff > span)
				span = diff;
		}
	}
	return span;
}
