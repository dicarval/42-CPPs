/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:06:13 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/02 16:18:47 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include "easyfind.tpp"

template<typename T>
typename T::iterator	easyfind(T &one, int sec);

template<typename T>
typename T::const_iterator	easyfind(const T &one, int sec);


#endif
