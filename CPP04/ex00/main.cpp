/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:14:53 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/17 18:06:58 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

void	test1()
{
	std::cout << "\n==========| TEST 1 |==========\n\n";

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void	test2()
{
	std::cout << "\n==========| TEST 2 |==========\n\n";

	Animal	Unknown;
	Unknown.makeSound();
	std::cout << std::endl;

	Cat	Pistache;
	Pistache.makeSound();
	std::cout << std::endl;

	Dog	Bolinhas;
	Bolinhas.makeSound();
	std::cout << std::endl;
}

void	test3()
{
	std::cout << "\n==========| TEST 3 |==========\n\n";

	std::cout << "Creating Normal Veterinary.\n";
	Animal	*normal_veterinary[]=
	{
		new Cat(),
		new Cat(),
		new Cat()
	};

	std::cout << "\nCreating Weird Veterinary.\n";
	WrongAnimal	*weird_veterinary[]=
	{
		new WrongCat(),
		new WrongCat(),
		new WrongCat()
	};

	std::cout << "\nNormal Veterinary:\n";
	for (int i = 0; i < 3; i++)
		normal_veterinary[i]->makeSound();


	std::cout << "\nWeird Veterinary:\n";
	for (int i = 0; i < 3; i++)
		weird_veterinary[i]->makeSound();

	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		delete normal_veterinary[i];
		delete weird_veterinary[i];
	}

}

int main()
{
	test1();
	test2();
	test3();
	return (0);
}
