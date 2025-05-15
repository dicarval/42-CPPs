/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_search.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:22:11 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/15 14:05:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::printSearch(int num)
{
	std::cout << "First name: ";
	std::cout << _contacts[num].searchFirstName() << std::endl;
	std::cout << "Last name: ";
	std::cout << _contacts[num].searchLastName() << std::endl;
	std::cout << "Nickname: ";
	std::cout << _contacts[num].searchNickname() << std::endl;
	std::cout << "Phone number: ";
	std::cout << _contacts[num].searchPhoneNum() << std::endl;
	std::cout << "Dark secret: ";
	std::cout << _contacts[num].searchDarkSecret() << std::endl;
}

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
		std::cout << input;
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
	std::cout <<std:: endl << "|     Index";
	std::cout << "|First Name";
	std::cout << "| Last Name";
	std::cout << "|  Nickname|" << std::endl;
	printAllPhoneBookContacts();
	std::cout << "|__________";
	std::cout << "|__________";
	std::cout << "|__________";
	std::cout << "|__________|" << std::endl;

}
