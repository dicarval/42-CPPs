/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:50:16 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/07 15:06:15 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//CONSTRUCTORS & DESTRUCTOR

Character::Character() : _name("Asdrubal")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &original)
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

Character&	Character::operator=(const Character &original)
{
	if (this != &original)
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
	}
	return (*this);
}

//SETTER

void	Character::setName(const std::string &newName)
{
	_name = newName;
}

//GETTER

const std::string&	Character::getName() const
{
	return (_name);
}

//MEMBER FUNCTIONS

bool	Character::_checkInvSpace(int idx)
{
	if (idx < 0 || idx > 3)
		return (true);
	else if (_inventory[idx] == NULL)
	{
		std::cout << _name << \
		 " > ! There is no Materia equiped in the slot " << (idx +1) << " !" << std::endl;
		return (true);
	}
	else
		return (false);
}

bool	Character::_checkInvSlot(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << _name << \
		" > ! You are trying to reach a non existant inventory space !" << std::endl;
		return (true);
	}
	return (false);
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << _name << " > ! There is no Materia to equip !" << std::endl;
		return ;
	}
	int	i = 0;
	while (i < 4 && _inventory[i])
		i++;
	if (i != 4)
	{
		_inventory[i] = m;
		std::cout << _name << " > * Materia \"" << _inventory[i]->getType() << \
		"\" set in the inventory space " << (i + 1) << " *" << std::endl;
	}
	else
		std::cout << _name << " > ! The inventory is full, there's only 4 inventory spaces available !"\
		 << std::endl;
}

void	Character::unequip(int idx)
{
	if (_checkInvSpace(idx) || _checkInvSlot(idx))
		return ;
	_inventory[idx] = NULL;
	std::cout << _name << " > * Inventory space " << (idx + 1) << " is now available *" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (_checkInvSpace(idx) || _checkInvSlot(idx))
		return ;
	std::cout << _name << " > ";
	_inventory[idx]->use(target);
}
