/* ************************************************************************** */
/*																		    */
/*														:::      ::::::::   */
/*   MutantStack.hpp								    :+:      :+:    :+:   */
/*												    +:+ +:+		 +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/10/08 14:50:02 by dicarval		  #+#    #+#		     */
/*   Updated: 2025/10/09 16:44:47 by dicarval		 ###   ########.fr       */
/*																		    */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &original);
		~MutantStack();

		MutantStack&	operator=(const MutantStack &original);

		//std::stack<int>::container_type blah;

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#endif

#include "MutantStack.tpp"
