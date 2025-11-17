/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:25:13 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/17 11:57:04 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"
#include "Container.hpp"

//CONSTRUCTORS & DESTRUCTOR
PmergeME::PmergeME()
{}

PmergeME::PmergeME(const PmergeME &original)
{
	*this = original;
}

PmergeME::~PmergeME()
{}

//OPERATORS
PmergeME&	PmergeME::operator=(const PmergeME &original)
{
	if(this != &original)
	{
		this->_vec = original._vec;
		this->_deq = original._deq;
	}
	return (*this);
}

//MEMBER FUNCTIONS
/* void	PmergeME::vecSort(std::vector<long> &leftVect, \
std::vector<long> &rightVect, std::vector<long> &vect)
{
	unsigned int leftSize = vect.size() / 2;
	unsigned int rightSize = vect.size() - leftSize;
	unsigned int i = 0, l = 0, r = 0;

	while (l < leftSize && r < rightSize)
	{
		if (leftVect[l] < rightVect[r])
			vect[i++] = leftVect[l++];
		else
			vect[i++] = rightVect[r++];
	}
	while (l < leftSize)
		vect[i++] = leftVect[l++];
	while (r < rightSize)
		vect[i++] = rightVect[r++];
} */

/* void	PmergeME::vecMergeSort(std::vector<long> &vect)
{
	unsigned int size = vect.size();
	if (size <= 1)
		return;
	int mid = size / 2;
	std::vector<long> leftVect;
	std::vector<long> rightVect;
	for(unsigned int i= 0; i < size; i++)
	{
		if (i < mid)
			leftVect.push_back(_vec[i]);
		else
			rightVect.push_back(_vec[i]);
	}
	vecMergeSort(leftVect);
	vecMergeSort(rightVect);
	vecSort(leftVect, rightVect, vect);
} */

void	PmergeME::printExec(std::vector<long> &vect)
{
	std::cout << "Before: ";
	for (std::vector<long>::const_iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << "After ";
	for (std::vector<long>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::fixed << std::setprecision(5);
	std::cout << std::endl << "Time to process a range of " << vect.size() << " elements of std::vector : "\
	<< _vecExecTime << " milliseconds" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements of std::deque : "\
	<< _deqExecTime << " milliseconds" << std::endl;
}

void	PmergeME::algoExec()
{
	struct timeval tStart, tEnd;
	std::vector<long> ogVector = _vec;
	Container<std::vector<long> > vect;
	Container<std::deque<long> > dequ;

	gettimeofday(&tStart, NULL);
	vect.mergeSort(_vec);
	gettimeofday(&tEnd, NULL);
	_vecExecTime = (tEnd.tv_sec - tStart.tv_sec) * 1000.0 + (tEnd.tv_usec - tStart.tv_usec) / 1000.0;
	gettimeofday(&tStart, NULL);
	dequ.mergeSort(_deq);
	gettimeofday(&tEnd, NULL);
	_deqExecTime = (tEnd.tv_sec - tStart.tv_sec) * 1000.0 + (tEnd.tv_usec - tStart.tv_usec) / 1000.0;

	printExec(ogVector);
}

void	PmergeME::converterToContainer(const std::vector<std::string> &input)
{
	for(std::vector<std::string>::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (atoll((*it).c_str()) > std::numeric_limits<unsigned int>::max())
			throw InvalidInput();
		_vec.push_back(atol((*it).c_str()));
	}
	for(std::vector<std::string>::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (atoll((*it).c_str()) > std::numeric_limits<unsigned int>::max())
			throw InvalidInput();
		_deq.push_back(atol((*it).c_str()));
	}
}

//EXCEPTIONS
const char*	PmergeME::InvalidInput::what() const throw()
{
	return ("invalid input introduced");
}
