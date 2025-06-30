/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:25:13 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 19:11:32 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		unsigned int	_highFives;

	public:
		FragTrap();
		FragTrap(const std::string& newFragTrap);
		FragTrap(const FragTrap& original);
		~FragTrap();

		void	highFivesGuys(void);

		unsigned int getHighFives();

		FragTrap& operator=(const FragTrap& original);
};

#endif
