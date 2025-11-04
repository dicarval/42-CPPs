/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:55:55 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/04 15:02:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer to A class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer to B class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer to C class" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference to A class" << std::endl;
	}
	catch(const std::exception& e){}

	try
	{
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference to B class" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference to C class" << std::endl;
	}
	catch(const std::exception& e){}
}

Base*	generate(void)
{
	int r = std::rand() % 3;
	switch (r)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return NULL;
}

int	main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)) ^ static_cast<unsigned int>(getpid()));

	for (int i = 0; i < 10; ++i)
		std::rand();
	Base*	ptr1 = generate();
	Base*	ptr2 = generate();
	Base*	ptr3 = generate();
	Base*	ptr4 = generate();
	Base*	ptr5 = generate();
	Base*	ptr6 = generate();

	identify(ptr1);
	delete ptr1;
	identify(ptr2);
	delete ptr2;
	identify(ptr3);
	delete ptr3;
	identify(*ptr4);
	delete ptr4;
	identify(*ptr5);
	delete ptr5;
	identify(*ptr6);
	delete ptr6;
}
