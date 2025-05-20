/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:42:57 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/20 13:08:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string str);
		Zombie(void);
		~Zombie(void);
		void	nameTheZombie(Zombie* newZombie, std::string newName);
		void	announce();
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif
