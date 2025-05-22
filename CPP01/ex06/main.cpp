/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:00:34 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/22 09:34:46 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	print_complain(int i)
{
	Harl	karen;
	int		case_n = i + 1;

	switch (case_n)
	{
		case 1:
			karen.complain("debug");
			//fallthrough
		case 2:
			karen.complain("info");
			//fallthrough
		case 3:
			karen.complain("warning");
			//fallthrough
		case 4:
			karen.complain("error");
			break ;
	}
}

int	main(int ac, char* av[])
{
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac == 2)
	{
		for(int i = 0; i < 4; i++)
		{
			if (av[1] == complains[i])
				return (print_complain(i), 0);
		}
		return(std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 0);
	}
	else
		return (std::cerr << "Wrong arguments number" << std::endl, 1);

}
