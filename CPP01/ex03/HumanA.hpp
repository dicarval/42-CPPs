/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:01:28 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/20 15:20:39 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
	std::string	name;
	Weapon&		weapon;

	public:
	HumanA(std::string	human_name, Weapon& type);
	~HumanA(void);
	void		attack(void);
};

#endif
