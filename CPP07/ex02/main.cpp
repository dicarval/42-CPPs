/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:59:40 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/06 13:18:23 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
void	set42(T const n)
{
	n = 42;
}

void	test2()
{
	Array<float> f(10);
	Array<char> c(12);

	std::cout << "\n----------Test2------------\n" << std::endl;
	c.iter(set42);
	std::cout << "f = ";
	for (unsigned int i = 0; i < f.size(); i++)
	{
		f[i] = 42.42;
		std::cout << f[i] << " ";
	}
	std::cout << f.size() << std::endl;
	std::cout << "c = ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << c.size() << std::endl;
}

void	test1()
{
	std::cout << "----------Test1------------\n" << std::endl;
	int* a = new int();
	std::cout << "a = " << *a << std::endl;
	delete a;

	std::cout << "---------------------------" << std::endl;
	Array<int>* b = new Array<int>(10);
	std::cout << "b = ";
	for (unsigned int i = 0; i < b->size(); i++)
		std::cout << (*b)[i] << " ";
	std::cout << b->size() << std::endl;
	b->iter(set42);
	std::cout << "b = ";
	for (unsigned int i = 0; i < b->size(); i++)
		std::cout << (*b)[i] << " ";
	std::cout << b->size() << std::endl;
	delete b;

	std::cout << "---------------------------" << std::endl;
	Array<int> c(15);
	std::cout << "c = ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << c.size() << std::endl;
	c.iter(set42);
	std::cout << "c = ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << c.size() << std::endl;

	Array<int> d;
	std::cout << "d = ";
	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << d.size() << std::endl;
	d = c;
	std::cout << "d = ";
	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << d.size() << std::endl;
}

int	main()
{
	try
	{
		test1();
		test2();
	}
	catch(std::exception &e)
	{
		std::cout <<std::endl << e.what() << std::endl;
	}
}
