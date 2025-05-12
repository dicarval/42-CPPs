/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:51:25 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/12 17:23:30 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


int	get_command(PhoneBook *Pb)
{
	std::string	input;

	while (LOOP)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
			Pb->add();
		if (input == "SEARCH")
			Pb->search();
		if (input == "EXIT")
			return (0);
	}
}

int	main(void)
{
	PhoneBook	PBook;

	get_command(&PBook);
	return (0);
}
