/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:22:19 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/17 11:47:16 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>

class PmergeME
{
	protected:
		std::vector<long>	_vec;
		double				_vecExecTime;

		std::deque<long>	_deq;
		double				_deqExecTime;

	public:
		PmergeME();
		PmergeME(const PmergeME &original);
		~PmergeME();

		PmergeME&	operator=(const PmergeME &original);

		void	converterToContainer(const std::vector<std::string> &input);
		void	algoExec();
		void	printExec(std::vector<long> &vect);

		class InvalidInput : public std::exception
		{
				virtual const char* what() const throw();
		};
};

#endif
