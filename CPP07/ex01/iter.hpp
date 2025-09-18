/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:29:20 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/18 15:23:45 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename t>
void printIt(t &tchar)
{
	std::cout << tchar << std::endl;
}
template <typename t>
void changeIt(t &tchar)
{
	static_cast<int>(tchar++);
	std::cout << tchar << std::endl;
}

template <typename t>
void printIt(const t &tchar)
{
	std::cout << tchar << std::endl;
}

/* template <typename T>
void iter(const T* array, size_t len, void (*func)(const T&))
{
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
} */

template <typename T>
void iter(T* array, size_t len, void (*func)(T&))
{
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}


#endif

