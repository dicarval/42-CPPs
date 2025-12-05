/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:14:43 by dicarval          #+#    #+#             */
/*   Updated: 2025/12/05 08:26:02 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "PmergeMe.hpp"

template <typename cont>
class Container : public PmergeMe
{
	public:
		Container();
		Container(const Container &original);
		~Container();

		Container&	operator=(const Container &original);

		void	mergeSort(cont &cntr);
		void	sort(cont &leftCont, cont &rightCont, cont &cntr);
};

#include "Container.tpp"

#endif
