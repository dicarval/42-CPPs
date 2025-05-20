/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:01:28 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/20 15:20:24 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
	std::string	name;
	Weapon		*weapon;

	public:
	HumanB(std::string	human_name);
	~HumanB(void);
	void		setWeapon(Weapon& type);
	void		attack(void);
};

#endif
