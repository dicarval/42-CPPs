/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:21:02 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/22 10:01:25 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde->nameTheZombie(&horde[i], name);
	return horde;
}
