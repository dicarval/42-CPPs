/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:22:13 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 18:38:57 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// CONSTRUCTORS & DESTRUCTOR

ScavTrap::ScavTrap() : ClapTrap(), _guardGate(false)
{
	_name = "Default";
	std::cout << _name << " constructor of ScavTrap called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& newScavTrapName) : ClapTrap(newScavTrapName), _guardGate(false)
{
	std::cout << "Name constructor of ScavTrap " << _name << " called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original)
{
	std::cout << "Copy constructor of ScavTrap " << _name << " called" << std::endl;
	_guardGate = original._guardGate;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap " << _name << " called" << std::endl;
}

// OPERATOR

ScavTrap&	ScavTrap::operator=(const ScavTrap& original)
{
	_name = original._name;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
	_guardGate = original._guardGate;
	std::cout << "Copy assignment operator of ScavTrap " << _name << " called" << std::endl;
	return (*this);
}

