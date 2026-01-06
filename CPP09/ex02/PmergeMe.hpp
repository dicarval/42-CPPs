/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:22:19 by dicarval          #+#    #+#             */
/*   Updated: 2026/01/05 18:07:20 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
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

class PmergeMe
{
	protected:
		std::vector<long>	_vec;
		double				_vecExecTime;

		std::list<long>	_list;
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
		void	mainPendSeparationVec(jacobVec &main, jacobVec &pend, long &pairSize, long &sizeVec);

		void	convertToContainer(const std::vector<std::string> &input);
		void	algoExec();
		void	printExec(std::vector<long> &vect);

		class InvalidInput : public std::exception
		{
				virtual const char* what() const throw();
		};
};

#endif
