/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:48:37 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/17 13:23:52 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	test1()
{
	std::cout << "\n==========| TEST 1 |==========\n\n";

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
}

void	test2()
{
	std::cout << "\n==========| TEST 2 |==========\n\n";

	std::cout << "Construction:\n";
	Animal	*veterinary[]=
	{
		new Cat(),
		new Cat(),
		new Cat(),
		new Dog(),
		new Dog(),
		new Dog()
	};

	std::cout << "\nDestruction:\n";
	for (int i = 0; i < 6; i++)
		delete veterinary[i];
}

void	test3()
{
	std::cout << "\n==========| TEST 3 |==========\n\n";

	Cat	*Patareco = new Cat();

	std::cout << "\nPatareco:\n";
	Patareco->printCatIdeas(0, 3);

	std::cout << std::endl;
	Patareco->setCatIdea("Lasanha!!", 0);
	Patareco->setCatIdea("Scratch my back!", 1);
	Patareco->setCatIdea("Scratch my back!", 2);
	Patareco->setCatIdea("Scratch my belly!", 3);
	Cat	*copy_cat = new Cat(*Patareco);
	//Cat	*copy_cat = new Cat();
	//*copy_cat = *Patareco;
	Patareco->setCatIdea("What a confortable box to sleep in...", 1);
	copy_cat->setCatIdea("Fur ball!", 0);

	std::cout << "\nPatareco: (" << Patareco->getCatBrain() << ")\n";
	Patareco->printCatIdeas(0, 3);
	std::cout << "\ncopy_cat: (" << copy_cat->getCatBrain() << ")\n";
	copy_cat->printCatIdeas(0, 3);

	std::cout << std::endl;

	delete Patareco;
	delete copy_cat;
}

int main()
{
	test1();
	test2();
	test3();
	return 0;
}
