/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsDiamondTrap.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:54:38 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/15 14:04:48 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	DiamondTrap::whoAmI()
{
	std::cout << "People call me " << _name << std::endl;
	std::cout << "But my real name is " << ClapTrap::_name << std::endl;
}
