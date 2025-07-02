/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:24:18 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 11:07:40 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//CONSTRUCTORS & DESTRUCTOR

ClapTrap::ClapTrap() : _name("Default"),\
 _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor of ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& newClapTrapName) : _name(newClapTrapName),\
 _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Name constructor of ClapTrap " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& original)
{
	std::cout << "Copy constructor of ClapTrap " << original._name << " called" << std::endl;
	*this = original;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of ClapTrap " << _name << " called" << std::endl;
}

//OPERATOR

ClapTrap&	ClapTrap::operator=(const ClapTrap& original)
{
	std::cout << "Copy assignment operator of ClapTrap " << original._name << " called" << std::endl;
	_name = original._name;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
	return (*this);
}

//GETTER

std::string	ClapTrap::getName()
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints()
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints()
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage()
{
	return (_attackDamage);
}
