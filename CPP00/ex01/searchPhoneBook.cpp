/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPhoneBook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:22:11 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/13 16:15:12 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::printColumn(std::string input)
{
	size_t		len;
	size_t		i;

	len = input.size();
	i = 0;
	if (len > 10)
	{
		while (i <= 8)
			std::cout << input[i++];
		std::cout << ".";
	}
	else
	{
		while ((9 - (i++)) != (len - 1))
			std::cout << " ";
		while (i <= 9)
			std::cout << input[i++];
	}
}

void	PhoneBook::printContact(int pos)
{
	std::string	input;
	size_t		i;

	std::cout << "|";
	i = 0;
	while (i++ != 9)
		std::cout << " ";
	std::cout << (pos + 1);
	std::cout << "|";
	input = _contacts[pos].searchFirstName();
	printColumn(input);
	std::cout << "|";
	input = _contacts[pos].searchLastName();
	printColumn(input);
	std::cout << "|";
	input = _contacts[pos].searchNickname();
	printColumn(input);
	std::cout << "|";
}

void	PhoneBook::printAllPhoneBookContacts()
{
	int	pos;

	pos = 0;
	while(pos <= _index)
	{
		printContact(pos++);
		std::cout << std::endl;
	}
}

void	PhoneBook::printPhoneBook()
{
	std::cout << "|     Index";
	std::cout << "|First Name";
	std::cout << "| Last Name";
	std::cout << "|  Nickname|" << std::endl;
	printAllPhoneBookContacts();
	std::cout << "|__________";
	std::cout << "|__________";
	std::cout << "|__________";
	std::cout << "|__________|" << std::endl;

}
