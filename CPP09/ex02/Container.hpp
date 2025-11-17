/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:14:43 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/17 11:11:24 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "PmergeME.hpp"

template <typename cont>
class Container : public PmergeME
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
