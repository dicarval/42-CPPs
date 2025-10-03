/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:09:45 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/03 15:09:50 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//CONSTRUCTORS & DESTRUCTOR

template<typename T>
Array<T>::Array() : _len(0), _array(NULL)
{
	_array = new T[_len];
}

template<typename T>
Array<T>::Array(unsigned int n) : _len(n), _array(NULL)
{
	_array = new T[_len];
	for (unsigned int i = 0; i < _len; ++i)
		_array[i] = T();
}

template<typename T>
Array<T>::Array(const Array &original) : _array(NULL)
{
	*this = original;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

//OPERATORS
template<typename T>
Array<T>&	Array<T>::operator=(const Array &original)
{
	if (this != &original)
	{
		if (_array)
			delete[] _array;
		_len = original._len;
		_array = new T[_len];
		for(unsigned int i = 0; i < _len; i++)
			_array[i] = original._array[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _len)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return _len;
}

template <typename T>
void	Array<T>::iter( void (*func)(T&))
{
	for (size_t i = 0; i < _len; i++)
		func(_array[i]);
}

