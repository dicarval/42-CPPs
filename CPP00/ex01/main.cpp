/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:51:25 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/13 16:49:09 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	get_command(PhoneBook *Pb)
{
	std::string	input;

	std::cout << "Welcome to My Awesome PhoneBook" << std::endl;
	std::cout << "How can I help you?" << std::endl;
	while (LOOP)
	{
		std::getline(std::cin, input);
		if (!std::cin)
			break ;
		else if (input == "ADD")
			Pb->add();
		else if (input == "SEARCH")
			Pb->search();
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "Not a valid command, try again" << std::endl;
		std::cout << "What's next?" << std::endl;
	}
	return (0);
}

int	main(void)
{
	PhoneBook	PBook;

	get_command(&PBook);
	return (0);
}
