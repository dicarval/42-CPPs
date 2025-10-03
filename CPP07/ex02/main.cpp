/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:59:40 by dicarval          #+#    #+#             */
/*   Updated: 2025/10/03 15:09:55 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
void set42(T const n)
{
	n = 42;
}

int	main()
{
	try
	{
		int* a = new int();
		std::cout << *a << std::endl;
		delete a;

		Array<int>* b = new Array<int>(10);
		for (unsigned int i = 0; i < b->size(); i++)
			std::cout << (*b)[i];
		std::cout << std::endl;
		b->iter(set42);
		for (unsigned int i = 0; i < b->size(); i++)
			std::cout << (*b)[i];
		std::cout << std::endl;
		delete b;

		Array<int> c(15);
		for (unsigned int i = 0; i < c.size(); i++)
			std::cout << c[i];
		std::cout << std::endl;
		c.iter(set42);
		for (unsigned int i = 0; i < c.size(); i++)
			std::cout << c[i];
		std::cout << std::endl;

		Array<int> d;
		for (unsigned int i = 0; i < d.size(); i++)
			std::cout << d[i];
		std::cout << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout <<std::endl << e.what() << std::endl;
	}
}
