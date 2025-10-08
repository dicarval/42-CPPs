/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:50:02 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/08 16:58:15 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		typename std::stack<T>	_stack;

	public:
		MutantStack();
		MutantStack(const MutantStack &original);
		~MutantStack();

		MutantStack&	operator=(const MutantStack &original);

	class iterator
	{
		iterator();
		iterator(const iterator &original);
		~iterator();

		iterator&	operator=(const iterator &original);
	}
};

#endif
