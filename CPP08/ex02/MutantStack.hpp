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
		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::reference reference;
		typedef typename container_type::const_reference const_reference;
		typedef typename container_type::size_type size_type;

		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;

		reference		operator[](size_type index);
		const_reference	operator[](size_type index) const;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

#endif

#include "MutantStack.tpp"
