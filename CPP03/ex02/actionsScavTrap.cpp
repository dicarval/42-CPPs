/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsScavTrap.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:46:40 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 16:18:13 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has 0 hit points, it's not possible to attack"\
		 << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy points available to attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << \
	_attackDamage << " points of damage" << std::endl;

}

void	ScavTrap::guardGate(void)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << "has 0 hit points, it's not possible to guard the gate"\
		 << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy points available to guard the gate" << std::endl;
		return ;
	}
	if (_guardGate == true)
	{
		std::cout << "ScavTrap " << _name << " is already in gate keeper mode" << std::endl;
		return ;
	}
	_energyPoints--;
	_guardGate = true;
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode" << std::endl;
	return ;
}
