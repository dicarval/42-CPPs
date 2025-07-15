/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionsFragTrap.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:43:21 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/15 12:05:53 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>

void	FragTrap::highFivesGuys(void)
{
	std::string	prompt;
	std:: string highFive = "5";

	if (!std::cin)
		return ;
	else if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no hit points to request FREAKING high fives"\
		 << std::endl;
		return ;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no energy points to request FREAKING high fives" << std::endl;
		return ;
	}
	std::cout << "\nWho's gonna give " << _name << " a FREAKING high five?" << std::endl;
	std::getline(std::cin, prompt);
	if (!std::cin)
	{
		std::cout << "C'mon!! You just broke the only way to get FREAKING high fives..." << std::endl;
		return ;
	}
	_energyPoints--;
	if (prompt != highFive)
		std::cout << "Sorry, no high five to " << _name << "..." << std::endl;
	else
	{
		std::cout << "You gave a FREAKING high five to " << _name << "!" << std::endl;
		_highFives++;
	}
	std::cout << "FragTrap " << _name << " got " << _highFives << " FREAKING high fives!" << std::endl;
}
