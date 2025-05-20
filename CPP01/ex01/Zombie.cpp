/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:52:51 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/20 13:09:25 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str) : name(str)
{
	std::cout << "Zombie " << name << " created" << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Zombie without name (yet) created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void	Zombie::nameTheZombie(Zombie* newZombie, std::string newName)
{
	newZombie->name = newName;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
