/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:01:36 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/08 17:30:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//CONSTRUCTORS & DESTRUCTOR

template<typename T>
MutantStack<T>::MutantStack()
{}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &original)
{
	*this = original;
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

//OPERATORS
template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack &original)
{
	if (this != &original)
	{
		std::stack<T> newStack;
		newStack = original._stack;
		std::swap(this->_stack, newStack);
	}
	return *this;
}
