/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:35:18 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/15 14:06:44 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//CONSTRUCTORS & DESTRUCTOR

FragTrap::FragTrap() : ClapTrap(), _highFives(0)
{
	std::cout << _name << " constructor of FragTrap called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& newFragTrap) : ClapTrap(newFragTrap), _highFives(0)
{
	std::cout << "Name constructor of FragTrap " << _name << " called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original)
{
	std::cout << "Copy constructor of FragTrap " << _name << " called" << std::endl;
	_highFives = original._highFives;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap " << _name << " called" << std::endl;
}

//OPERATOR

FragTrap&	FragTrap::operator=(const FragTrap& original)
{
	_name = original._name;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
	_highFives = original._highFives;
	std::cout << "Copy assignment operator of FragTrap " << _name << " called" << std::endl;
	return (*this);
}

//GETTER

unsigned int	FragTrap::getHighFives()
{
	return (_highFives);
}
