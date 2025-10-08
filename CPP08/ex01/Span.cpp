/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:00:52 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/08 14:27:43 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//CONSTRUCTORS & DESTRUCTOR
Span::Span()
{
	_theVector.reserve(0);
}

Span::Span(const unsigned int &nb)
{
	_theVector.reserve(nb);
}

Span::Span(const Span &original)
{
	*this = original;
}

Span::~Span()
{}

//OPERATORS
Span&	Span::operator=(const Span &original)
{
	if (this != &original)
	{
		if (original._theVector.size() > _theVector.capacity())
			throw std::length_error("Span::operator= : source has more elements than destination capacity");
		std::vector<int> newVector;
		newVector.reserve(original._theVector.capacity());
		std::swap(this->_theVector, newVector);
	}
	return *this;
}

//MEMBER FUNCTIONS
void	Span::addNumber(const int &newNb)
{
	if (_theVector.size() == _theVector.capacity())
		throw std::length_error("Span::addNumber : Span list is full, no more numbers can be added");
	_theVector.push_back(newNb);
}

void	Span::addRange(const int &begin, const int &end)
{
	unsigned int diff = (begin > end) ? (begin - end) : (end - begin);
	unsigned int availableSpace = _theVector.capacity() - _theVector.size();
	if (diff <= availableSpace && diff && diff <= INT_MAX)
	{
		int direction = (begin < end) ? 1 : -1;
		for (unsigned int i = 0; i <= diff; i++)
			addNumber (begin + static_cast<int>(i * direction));
	}
	else
		throw std::length_error("Span::addRange : Invalid Range");
}

unsigned int	Span::shortestSpan()
{
	if (_theVector.size() <= 1)
		throw LessThanTwo();

	unsigned int span = UINT_MAX;
	for (unsigned int iter = 0; iter < _theVector.size(); iter++)
	{
		for (unsigned int i = iter + 1; i < _theVector.size(); i++)
		{
			unsigned int diff = (_theVector[iter] > _theVector[i])\
			 ? (_theVector[iter] - _theVector[i]) : (_theVector[i] - _theVector[iter]);
			if (diff < span)
				span = diff;
		}
	}
	return span;
}

unsigned int	Span::longestSpan()
{
	if (_theVector.size() <= 1)
		throw LessThanTwo();

	unsigned int span = 0;
	for (unsigned int iter = 0; iter < _theVector.size(); iter++)
	{
		for (unsigned int i = iter + 1; i < _theVector.size(); i++)
		{
			unsigned int diff = (_theVector[iter] > _theVector[i])\
			 ? (_theVector[iter] - _theVector[i]) : (_theVector[i] - _theVector[iter]);
			if (diff > span)
				span = diff;
		}
	}
	return span;
}

const char*	Span::LessThanTwo::what() const throw()
{
	return ("The vector has less than two numbers");
}
