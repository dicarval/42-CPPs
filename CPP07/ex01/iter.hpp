/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:29:20 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/06 10:19:04 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename t>
void changeIt(t &elem)
{
	elem += 1;
	std::cout << elem;
}

template <typename t>
void printIt(const t &elem)
{
	std::cout << elem;
}

template <typename T>
void iter(const T* array, const size_t len, void (*func)(const T&))
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
	std::cout << std::endl;
}

template <typename T>
void iter(T* array, const size_t len, void (*func)(T&))
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
	std::cout << std::endl;
}


#endif

