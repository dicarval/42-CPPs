/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:00:52 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/07 12:03:59 by dicarval         ###   ########.fr       */
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
void	Span::addNumber(const long &newNb)
{
	if (_theVector.size() == _theVector.capacity())
		throw std::length_error("Span::addNumber : Span list is full, no more numbers can be added");
	else if (newNb > std::numeric_limits<int>::max() || newNb < std::numeric_limits<int>::min())
		throw OutOfRange();
	_theVector.push_back(newNb);
}

void	Span::addRange(const long &begin, const long &end)
{
	unsigned long diff = (begin > end) ? (begin - end) : (end - begin);
	if (diff <= std::numeric_limits<unsigned int>::max())
	{
		int direction = (begin <= end) ? 1 : -1;
		for (unsigned long i = 0; i <= diff; i++)
			addNumber (begin + static_cast<long>(i * direction));
	}
	else
		throw std::length_error("Span::addRange : Invalid Range");
}

unsigned long	Span::shortestSpan()
{
	if (_theVector.size() <= 1)
		throw LessThanTwo();

	unsigned long span = std::numeric_limits<unsigned int>::max();
	for (unsigned int iter = 0; iter < _theVector.size(); iter++)
	{
		for (unsigned int i = iter + 1; i < _theVector.size(); i++)
		{
			long iterNumber = _theVector[iter];
			long iNumber = _theVector[i];
			unsigned long diff = (iterNumber > iNumber)\
			 ? (iterNumber - iNumber) : (iNumber - iterNumber);
			if (diff < span)
				span = diff;
		}
	}
	return span;
}

unsigned long	Span::longestSpan()
{
	if (_theVector.size() <= 1)
		throw LessThanTwo();

	unsigned long span = 0;
	for (unsigned int iter = 0; iter < _theVector.size(); iter++)
	{
		for (unsigned int i = iter + 1; i < _theVector.size(); i++)
		{
			long iterNumber = _theVector[iter];
			long iNumber = _theVector[i];
			unsigned long diff = (iterNumber > iNumber)\
			 ? (iterNumber - iNumber) : (iNumber - iterNumber);
			if (diff > span)
				span = diff;
		}
	}
	return span;
}

//EXCEPTIONS
const char*	Span::LessThanTwo::what() const throw()
{
	return ("The vector has less than two numbers");
}

const char*	Span::OutOfRange::what() const throw()
{
	return ("Number is out of range");
}
