/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsClapTrap.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:54:35 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 15:56:55 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has already 0 hit points, it's not possible to be repaired"\
		 << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points available to be repaired"\
		 << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " was repaired in " << amount << " hit points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has already 0 hit points, it's not possible to"\
		" take more damage" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " was hit with " << amount << " points of damage" <<\
	 std::endl;
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has 0 hit points, it's not possible to attack"\
		 << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points available to attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << \
	_attackDamage << " points of damage" << std::endl;
}
