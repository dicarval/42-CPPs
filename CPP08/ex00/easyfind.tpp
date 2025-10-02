/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:06:48 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/02 16:13:36 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
typename T::iterator	easyfind(T &one, int sec)
{
	std::cout << "Non-const: ";
	typename T::iterator it = std::find(one.begin(), one.end(), sec);
	if (it == one.end())
		throw std::out_of_range("easyfind: value not found");
	return it;
}

template<typename T>
typename T::const_iterator	easyfind(const T &one, int sec)
{
	std::cout << "Const: ";
	typename T::const_iterator it = std::find(one.begin(), one.end(), sec);
	if (it == one.end())
		throw std::out_of_range("easyfind: value not found");
	return it;
}
