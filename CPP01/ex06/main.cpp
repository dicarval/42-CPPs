/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:00:34 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/21 18:45:19 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	print_complain(int i)
{
	Harl	Karen;
	int		case_n = i + 1;

	switch (case_n)
	{
		case 1:
			Karen.complain("debug");
			Karen.complain("info");
			Karen.complain("warning");
			Karen.complain("error");
			break ;
		case 2:
			Karen.complain("info");
			Karen.complain("warning");
			Karen.complain("error");
			break ;
		case 3:
			Karen.complain("warning");
			Karen.complain("error");
			break ;
		case 4:
			Karen.complain("error");
			break ;
	}
}

int	main(int ac, char* av[])
{
	Harl	Karen;
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac == 2)
	{
		for(int i = 0; i < 4; i++)
		{
			if (av[1] == complains[i])
				return (print_complain(i), 0);
		}
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	else
		std::cerr << "Wrong arguments number" << std::endl;
	return (1);

}
