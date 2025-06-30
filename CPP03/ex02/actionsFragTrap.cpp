/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsFragTrap.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:43:21 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/30 18:02:00 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>

void	FragTrap::highFivesGuys(void)
{
	std::string	prompt;

	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no hit points to request FREAKING high fives"\
		 << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no energy points to request FREAKING high fives" << std::endl;
		return ;
	}
	if (!std::cin)
	{
		std::cout << "C'mon!! You just broke the only way to get FREAKING high fives..." << std::endl;
		return ;
	}
	std::cout << "Who's gonna give " << _name << " a FREAKING high five?" << std::endl;
	std::getline(std::cin, prompt);
	std:: string highFive = "FREAKING HIGH FIVE";
	_energyPoints--;
	if (prompt != highFive)
	{
		std::cout << "No FREAKING high five for " << _name << "..." << std::endl;
		return ;
	}
	else
		std::cout << "You gave a FREAKING high five to " << _name << "!" << std::endl;
	_highFives++;
}
