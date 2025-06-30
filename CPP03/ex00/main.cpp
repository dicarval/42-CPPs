/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:24:59 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 14:10:49 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Manel("Manel");
	ClapTrap	Joaquim("Joaquim");
	ClapTrap	Vanessa(Manel);

	Manel.attack("Gary");
	Manel.beRepaired(4);
	Manel.attack("Rita");
	Manel.attack("Homer");
	Manel.attack("TG40");
	Manel.beRepaired(1);
	Manel.beRepaired(5);
	Manel.attack("WD40");
	Manel.attack("Joana");
	Manel.attack("Delta");
	Manel.beRepaired(1);
	Manel.attack("Vasco");
	Joaquim.takeDamage(4);
	Joaquim.takeDamage(6);
	Joaquim.beRepaired(4);
	return (0);
}
