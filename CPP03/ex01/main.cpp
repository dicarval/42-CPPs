/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:24:59 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/15 11:41:10 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Bartolomeu("Bartolomeu");
	std::cout << "\n----- " << Bartolomeu.getName() << " -----\n\n";
	std::cout << "Attack: ";
	Bartolomeu.attack("Wall");
	std::cout << "\nTake damage: ";
	Bartolomeu.takeDamage(2);
	std::cout << "\nBe repaired: ";
	Bartolomeu.beRepaired(1);
	std::cout << "\nHit Points: " << Bartolomeu.getHitPoints();
	std::cout << "\nEnergy Points: " << Bartolomeu.getEnergyPoints() << "\n\n";
	//Bartolomeu.guardGate();

	ScavTrap	Rogerio("Rogerio");
	std::cout << "\n----- " << Rogerio.getName() << " -----\n\n";
	std::cout << "Attack: ";
	Rogerio.attack("Wall");
	std::cout << "\nTake damage: ";
	Rogerio.takeDamage(2);
	std::cout << "\nBe repaired: ";
	Rogerio.beRepaired(1);
	std::cout << "\nGuard Gate: ";
	Rogerio.guardGate();
	std::cout << "\nHit Points: " << Rogerio.getHitPoints();
	std::cout << "\nEnergy Points: " << Rogerio.getEnergyPoints() << "\n\n";

	// ScavTrap	Copycat;
	// Copycat = Rogerio;
	ScavTrap Copycat(Rogerio);

	std::cout << "\n----- " << Copycat.getName() << " (copycat) -----\n\n";
	std::cout << "Attack: ";
	Copycat.attack("Wall");
	std::cout << "\nTake damage: ";
	Copycat.takeDamage(2);
	std::cout << "\nBe repaired: ";
	Copycat.beRepaired(1);
	std::cout << "\nGuard Gate: ";
	Rogerio.guardGate();
	std::cout << "\nHit Points: " << Copycat.getHitPoints();
	std::cout << "\nEnergy Points: " << Copycat.getEnergyPoints() << "\n";
	std::cout << "\n-------------------------------------\n\n";
}
