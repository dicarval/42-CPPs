/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:25:13 by dicarval          #+#    #+#             */
/*   Updated: 2026/01/07 15:38:05 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//CONSTRUCTORS & DESTRUCTOR
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &original)
{
	*this = original;
}

PmergeMe::~PmergeMe()
{}

//OPERATORS
PmergeMe&	PmergeMe::operator=(const PmergeMe &original)
{
	if(this != &original)
	{
		this->_vec = original._vec;
		this->_list = original._list;
	}
	return (*this);
}

//MEMBER FUNCTIONS
void	PmergeMe::printExec(std::vector<long> &vect)
{
	std::cout << "Before:         ";
	for (std::vector<long>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << "After (vector): ";
	for (std::vector<long>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << "After (list):   ";
	for (std::vector<long>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::fixed << std::setprecision(5);
	std::cout << std::endl << "Time to process a range of " << vect.size() \
	<< " elements of std::vector: " << _vecExecTime << " milliseconds" << std::endl;
	std::cout << "Time to process a range of " << _list.size() << " elements of std::list:   "\
	<< _listExecTime << " milliseconds" << std::endl;
}

void	PmergeMe::algoExec()
{
	struct timeval tStart, tEnd;
	std::vector<long> ogVector = _vec;

	gettimeofday(&tStart, NULL);
	mergeInsertionVec(1);
	gettimeofday(&tEnd, NULL);
	_vecExecTime = (tEnd.tv_sec - tStart.tv_sec) * 1000.0 + (tEnd.tv_usec - tStart.tv_usec) / 1000.0;
	gettimeofday(&tStart, NULL);
	mergeInsertionList(1);
	gettimeofday(&tEnd, NULL);
	_listExecTime = (tEnd.tv_sec - tStart.tv_sec) * 1000.0 + (tEnd.tv_usec - tStart.tv_usec) / 1000.0;
	printExec(ogVector);
}

void	PmergeMe::convertToContainer(const std::vector<std::string> &input)
{
	for(std::vector<std::string>::const_iterator it = input.begin(); it != input.end(); it++)
	{
		long long inputIn = atoll((*it).c_str());
		if (inputIn > std::numeric_limits<int>::max() || inputIn < 0)
			throw InvalidInput();
		_vec.push_back(atol((*it).c_str()));
	}
	std::vector<long> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	for(std::vector<long>::iterator it = tmp.begin(); it != tmp.end(); it++)
	{
		if ((it + 1) != tmp.end() && *it == *(it + 1))
			throw InvalidInput();
	}
	tmp.clear();
	for(std::vector<long>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
		_list.push_back(*it);
}

//EXCEPTIONS
const char*	PmergeMe::InvalidInput::what() const throw()
{
	return ("invalid input introduced");
}
