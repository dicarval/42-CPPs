/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:13:41 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 19:17:04 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		bool	_guardGate;

	public:
		ScavTrap();
		ScavTrap(const std::string& newScavTrapName);
		ScavTrap(const ScavTrap& original);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
		bool	getGuardGate();

		ScavTrap& operator=(const ScavTrap& original);
};


#endif
