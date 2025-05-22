/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:01:15 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/22 11:22:42 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string	human_name) : name(human_name)
{}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon& weapon_set)
{
	weapon = &weapon_set;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
