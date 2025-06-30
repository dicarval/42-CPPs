/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:24:59 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 17:11:52 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Joaozinho("Joaozinho");
	std::cout << "----- " << Joaozinho.getName() << " -----\n\n";
	std::cout << "	Attack: ";
	Joaozinho.attack("Monitor");
	std::cout << "\n	Take damage: ";
	Joaozinho.takeDamage(2);
	std::cout << "\n	Be repaired: ";
	Joaozinho.beRepaired(1);
	std::cout << "\n	3 HighFives request:\n";
	Joaozinho.highFivesGuys();
	Joaozinho.highFivesGuys();
	Joaozinho.highFivesGuys();
	std::cout << "\n	Hit Points: " << Joaozinho.getHitPoints();
	std::cout << "\n	Energy Points: " << Joaozinho.getEnergyPoints();
	std::cout << "\n	HighFives: " << Joaozinho.getHighFives() << "\n\n";
}
