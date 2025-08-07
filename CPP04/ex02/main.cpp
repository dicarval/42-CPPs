/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:48:37 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/07 15:01:32 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	test1()
{
	std::cout << "\n==========| TEST 1 |==========\n\n";

	const AAnimal	*j = new Dog();
	const AAnimal	*i = new Cat();

	Dog	Bolinhas;
	Dog	Bobby;
	Dog	Tutu(Bobby);

	Bobby = Bolinhas;

	delete j;
	delete i;
}

void	test2()
{
	std::cout << "\n==========| TEST 2 |==========\n\n";

	Animal		*Bigfoot = new Animal();
	AAnimal		*Tareco = new Cat();
	//AAnimal	*LochNess = new AAnimal();

	std::cout << std::endl;
	Bigfoot->makeSound();
	std::cout << std::endl;
	Tareco->makeSound();
	std::cout << std::endl;

	delete Bigfoot;
	delete Tareco;
}

int main()
{
	test1();
	test2();
	return 0;
}
