/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:24:59 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 19:17:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Roberto;
    std::cout << "------------------------------\n\n";
	Roberto.whoAmI();
	std::cout << "\nAttack:\n";
	Roberto.attack("Monitor");

	std::cout << "\nTake damage:\n";
	Roberto.takeDamage(2);

	std::cout << "\nBe repaired:\n";
	Roberto.beRepaired(1);

	std::cout << "\nGuard Gate:\n";
	Roberto.guardGate();
	Roberto.guardGate();

	std::cout << "\n3 HighFives request:\n";
	Roberto.highFivesGuys();
	Roberto.highFivesGuys();
	Roberto.highFivesGuys();

	std::cout << "\n	Hit Points: " << Roberto.getHitPoints();
	std::cout << "\n	Energy Points: " << Roberto.getEnergyPoints();
	std::cout << "\n	Attack Damage: " << Roberto.getAttackDamage();
	std::cout << "\n	Guard Gate: " << Roberto.getGuardGate();
	std::cout << "\n	HighFives: " << Roberto.getHighFives() << "\n\n";
	std::cout << "------------------------------\n\n";

    DiamondTrap Joaquim("Joaquim");
	std::cout << "------------------------------\n\n";
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

	std::cout << "\n	Hit Points: " << Joaquim.getHitPoints();
	std::cout << "\n	Energy Points: " << Joaquim.getEnergyPoints();
	std::cout << "\n	Attack Damage: " << Joaquim.getAttackDamage();
	std::cout << "\n	Guard Gate: " << Joaquim.getGuardGate();
	std::cout << "\n	HighFives: " << Joaquim.getHighFives() << "\n\n";
	std::cout << "------------------------------\n\n";

	DiamondTrap	Copycat("Copycat");
	Copycat = Joaquim;
	//ScavTrap Copycat(Joaquim);
	std::cout << "------------------------------\n\n";
	Copycat.whoAmI();
	std::cout << "\n	Hit Points: " << Copycat.getHitPoints();
	std::cout << "\n	Energy Points: " << Copycat.getEnergyPoints();
	std::cout << "\n	Attack Damage: " << Copycat.getAttackDamage();
	std::cout << "\n	Guard Gate: " << Copycat.getGuardGate();
	std::cout << "\n	HighFives: " << Copycat.getHighFives() << "\n\n";
	std::cout << "------------------------------\n\n";;
}
