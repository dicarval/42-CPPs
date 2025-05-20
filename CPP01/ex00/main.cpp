/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:01:59 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/20 09:17:25 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* half_dead;
	std::string	cool_name = "Cool half_dead";
	std::string	name = "Ugly half_dead";

	half_dead = newZombie(cool_name);
	randomChump(name);
	delete half_dead;
}
