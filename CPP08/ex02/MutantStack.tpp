/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:01:36 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/07 13:43:55 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//CONSTRUCTORS & DESTRUCTOR
template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &original) : std::stack<T>(original)
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
	std::stack<T>::operator=(original);
	return *this;
}

template<typename T>
typename MutantStack<T>::reference	MutantStack<T>::operator[](size_type index)
{
	return this->c[index];
}

template<typename T>
typename MutantStack<T>::const_reference	MutantStack<T>::operator[](size_type index) const
{
	return this->c[index];
}

//MEMBER FUNCTIONS
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return this->c.rend();
}
