/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:22:19 by dicarval          #+#    #+#             */
/*   Updated: 2026/01/06 16:51:13 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>

typedef struct s_jacobVec
{
	std::vector<long>			numbers;
	std::vector<std::string>	aOrB;
	std::vector<long>			position;
}				jacobVec;

typedef struct s_jacobList
{
	std::list<long>			numbers;
	std::list<std::string>	aOrB;
	std::list<long>			position;
}				jacobList;

class PmergeMe
{
	protected:
		std::vector<long>	_vec;
		double				_vecExecTime;

		std::list<long>		_list;
		double				_listExecTime;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &original);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe &original);

		void	mergeInsertionVec(long pairSize);
		void	pairSortingVec(long &pairSize, long &sizeVec);
		void	binaryInsertionVec(long &pairSize, long &sizeVec);
		void	binarySearchVec(jacobVec &main, jacobVec &pend, long &pairSize, long insertions, long jacobsthalN);
		bool	mainPendSeparationVec(jacobVec &main, jacobVec &pend, long &pairSize, long &sizeVec);
		void	insertPairInMainVec(jacobVec &main, jacobVec &pend, long m, long &pairSize, long &pendIndex);

		void	mergeInsertionList(long pairSize);
		void	pairSortingList(long &pairSize, long &sizeList);
		void	binaryInsertionList(long &pairSize, long &sizeList);
		void	binarySearchList(jacobList &main, jacobList &pend, long &pairSize, long insertions, long jacobsthalN);
		bool	mainPendSeparationList(jacobList &main, jacobList &pend, long &pairSize, long &sizeList);
		void	insertPairInMainList(jacobList &main, jacobList &pend, long m, long &pairSize, long &pendIndex);


		void	convertToContainer(const std::vector<std::string> &input);
		void	algoExec();
		void	printExec(std::vector<long> &vect);

		class InvalidInput : public std::exception
		{
				virtual const char* what() const throw();
		};
};

#endif
