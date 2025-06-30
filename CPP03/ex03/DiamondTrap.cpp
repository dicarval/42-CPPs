/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:17:42 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 19:14:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// CONSTRUCTORS & DESTRUCTOR

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), _name("Default")
{
	std::cout << _name << " constructor of DiamondTrap called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"),  _name(name)
{
	std::cout << "Name constructor of DiamondTrap " << _name << " called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& original) : ScavTrap(original), FragTrap(original)
{
	std::cout << "Copy constructor of DiamondTrap " << _name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap " << _name << " called" << std::endl;
}

// OPERATOR

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& original)
{
	_name = original._name;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
	_guardGate = original._guardGate;
	_highFives = original._highFives;
	std::cout << "Copy assignment operator of DiamondTrap " << _name << " called" << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My first name is " << _name << "!" << std::endl;
	std::cout << "But my complete name is " << ClapTrap::_name << std::endl;
}
