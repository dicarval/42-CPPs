/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:28:51 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/03 15:09:22 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &first, T &second)
{
	T temp;
	temp = first;
	first = second;
	second = temp;
}

template <typename T>
T	min(T &first, T &second)
{
	if (first < second)
		return first;
	else
		return second;
}

template <typename T>
T	max(T &first, T &second)
{
	if (first > second)
		return first;
	else
		return second;
}


#endif
