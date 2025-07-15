/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:24:59 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/15 11:43:54 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Camoes("Camoes");
	std::cout << "\n----- " << Camoes.getName() << " -----\n\n";
	std::cout << "Attack: ";
	Camoes.attack("Pessoa");
	std::cout << "\nTake damage: ";
	Camoes.takeDamage(2);
	std::cout << "\nBe repaired: ";
	Camoes.beRepaired(1);
	std::cout << "\n3 HighFives request:\n";
	Camoes.highFivesGuys();
	Camoes.highFivesGuys();
	Camoes.highFivesGuys();
	std::cout << "\nHit Points: " << Camoes.getHitPoints();
	std::cout << "\nEnergy Points: " << Camoes.getEnergyPoints();
	std::cout << "\nHighFives: " << Camoes.getHighFives() << "\n";
	std::cout << "\n-------------------------------------\n\n";
}
