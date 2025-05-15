/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:51:25 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/15 14:19:56 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	get_command(PhoneBook *Pb)
{
	std::string	input;

	system("clear");
	std::cout << "Welcome to My Awesome PhoneBook" << std::endl;
	std::cout << "How can I help you?" << std::endl;
	while (LOOP)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
			Pb->add();
		else if (input == "SEARCH")
			Pb->search();
		else if (input == "EXIT")
			return (SUCCESS);
		else if (std::cin)
			std::cout << "Not a valid command, try again" << std::endl;
		if (!std::cin)
			return (UNSUCCESS);
		system("sleep 1");
		system("clear");
		std::cout << "What's next?" << std::endl;
	}
	return (SUCCESS);
}

int	main(void)
{
	PhoneBook	PBook;
	int			flag;

	flag = get_command(&PBook);
	return (flag);
}
