/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:21:20 by dicarval          #+#    #+#             */
/*   Updated: 2025/12/30 12:20:36 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Container.hpp"

//CONSTRUCTORS & DESTRUCTOR
template<typename cont>
Container<cont>::Container()
{}

template<typename cont>
Container<cont>::Container(const Container &original)
{
	*this = original;
}

template<typename cont>
Container<cont>::~Container()
{}

//OPERATORS
template<typename cont>
Container<cont>&	Container<cont>::operator=(const Container &original)
{
	(void)original;
	return (*this);
}

//MEMBER FUNCTIONS
template<typename cont>
void	Container<cont>::sort(cont &leftCont, \
cont &rightCont, cont &cntr)
{
	unsigned int leftSize = cntr.size() / 2;
	unsigned int rightSize = cntr.size() - leftSize;
	unsigned int i = 0, l = 0, r = 0;

	while (l < leftSize && r < rightSize)
	{
		/* if (leftCont[l] < rightCont[r])
			throw InvalidInput(); */
		if (leftCont[l] < rightCont[r])
			cntr[i++] = leftCont[l++];
		else
			cntr[i++] = rightCont[r++];
	}
	while (l < leftSize)
		cntr[i++] = leftCont[l++];
	while (r < rightSize)
		cntr[i++] = rightCont[r++];
}

template<typename cont>
void	Container<cont>::mergeSort(cont &cntr)
{
	unsigned int size = cntr.size();
	if (size <= 1)
		return;
	unsigned int mid = size / 2;
	cont leftCont;
	cont rightCont;
	for(unsigned int i= 0; i < size; i++)
	{
		if (i < mid)
			leftCont.push_back(cntr[i]);
		else
			rightCont.push_back(cntr[i]);
	}
	mergeSort(leftCont);
	mergeSort(rightCont);
	sort(leftCont, rightCont, cntr);
}


