/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:50:16 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/03 17:08:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//CONSTRUCTORS & DESTRUCTOR

Character::Character() : _name("Asdrubal")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& original)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = original;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

//OPERATOR

Character&	Character::operator=(const Character& original)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = NULL;
		if (original._inventory[i])
			_inventory[i] = original._inventory[i]->clone();
	}
	_name = original._name;
	return (*this);
}

//SETTER

void	Character::setName(const std::string& newName)
{
	_name = newName;
}

//GETTER

const std::string&	Character::getName() const
{
	return (_name);
}

//MEMBER FUNCTIONS

bool	Character::checkInvSpace(int idx)
{
	if (idx < 0 || idx > 3)
		return (false);
	else if (_inventory[idx] == NULL)
		return (true);
	else
		return (false);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (checkInvSpace(i) == true)
		{
			_inventory[i] == m;
			std::cout << "Materia set in the inventory space " << (i + 1) << std::endl;
			return ;
		}
		else if (i == 3)
		{
			std::cout << "The inventory is full, there's only 4 inventory spaces" << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (checkInvSpace(idx) == true)
	{
		std::cout << "Inventory space " << (idx + 1) << " is already empty" << std::endl;
		return ;
	}
	_inventory[idx] = NULL;
	std::cout << "Inventory space " << (idx + 1) << " is now available" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > 0 || idx < 3)
		return ;
	std::cout << _name << " > ";
	_inventory[idx]->use(target);
	delete _inventory[idx];
	_inventory[idx] = NULL;
}
