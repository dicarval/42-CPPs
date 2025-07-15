/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:24:59 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/15 11:59:20 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Default;
	std::cout << "\n------------------------------\n\n";
	Default.whoAmI();

	std::cout << "\nAttack:\n";
	Default.attack("Monitor");

	std::cout << "\nTake damage:\n";
	Default.takeDamage(2);

	std::cout << "\nBe repaired:\n";
	Default.beRepaired(1);

	std::cout << "\nGuard Gate:\n";
	Default.guardGate();
	Default.guardGate();

	std::cout << "\n3 HighFives request:\n";
	Default.highFivesGuys();
	Default.highFivesGuys();
	Default.highFivesGuys();

	std::cout << "\nHit Points: " << Default.getHitPoints();
	std::cout << "\nEnergy Points: " << Default.getEnergyPoints();
	std::cout << "\nAttack Damage: " << Default.getAttackDamage();
	std::cout << "\nGuard Gate: " << Default.getGuardGate();
	std::cout << "\nHighFives: " << Default.getHighFives() << "\n";
	std::cout << "\n------------------------------\n\n";

	DiamondTrap Joaquim("Joaquim");
	std::cout << "\n------------------------------\n\n";
	Joaquim.whoAmI();
	std::cout << "\nAttack:\n";
	Joaquim.attack("Monitor");

	std::cout << "\nTake damage:\n";
	Joaquim.takeDamage(2);

	std::cout << "\nBe repaired:\n";
	Joaquim.beRepaired(1);

	std::cout << "\nGuard Gate:\n";
	Joaquim.guardGate();
	Joaquim.guardGate();

	std::cout << "\n3 HighFives request:\n";
	Joaquim.highFivesGuys();
	Joaquim.highFivesGuys();
	Joaquim.highFivesGuys();

	std::cout << "\nHit Points: " << Joaquim.getHitPoints();
	std::cout << "\nEnergy Points: " << Joaquim.getEnergyPoints();
	std::cout << "\nAttack Damage: " << Joaquim.getAttackDamage();
	std::cout << "\nGuard Gate: " << Joaquim.getGuardGate();
	std::cout << "\nHighFives: " << Joaquim.getHighFives() << "\n\n";
	std::cout << "------------------------------\n\n";

	DiamondTrap	Copycat("Copycat");
	Copycat = Joaquim;
	//ScavTrap Copycat(Joaquim);
	std::cout << "\n------------------------------\n\n";
	Copycat.whoAmI();
	std::cout << "\nHit Points: " << Copycat.getHitPoints();
	std::cout << "\nEnergy Points: " << Copycat.getEnergyPoints();
	std::cout << "\nAttack Damage: " << Copycat.getAttackDamage();
	std::cout << "\nGuard Gate: " << Copycat.getGuardGate();
	std::cout << "\nHighFives: " << Copycat.getHighFives() << "\n\n";
	std::cout << "------------------------------\n\n";;
}
