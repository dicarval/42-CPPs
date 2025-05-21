/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:21:05 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/21 10:11:38 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string new_type) : type(new_type)
{}

Weapon::~Weapon()
{}

void	Weapon::setType(const std::string new_type)
{
	if (new_type.empty())
	{
		type = "hands";
		return ;
	}
	type = new_type;
}

const std::string&	Weapon::getType()
{
	return (type);
}
