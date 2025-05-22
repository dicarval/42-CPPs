/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:26:45 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/22 09:36:48 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my triple 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	<< std::endl << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
	<< std::endl << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
	<< std::endl << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	std::string levels[] = {"debug", "info", "warning", "error"};

	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
}
