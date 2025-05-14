/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:13 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/14 12:09:12 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_index = -1;
	_oldest = -1;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Exiting My Awesome PhoneBook" << std::endl;
}

void	PhoneBook::insertion_stopped()
{
	std::cout << "Insertion stopped" << std::endl;
}

void	PhoneBook::search()
{
	std::string	index;
	int			num;

	printPhoneBook();
	std::cout << "Please insert wanted Contact index: ";
	std::getline(std::cin, index);
	if (!std::cin)
		return (insertion_stopped());
	if (index[0] >= '1' && index[0] <= '8' && !index[1])
	{
		num = std::atoi(index.c_str()) - 1;
		if (num > _index)
		{
			std::cout << "Index is out of range or wrong." << std::endl;
			return ;
		}
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
	else
		std::cout << "Index is out of range or wrong.\n";
}


void	PhoneBook::add()
{
	if (_index == 7)
	{
		++_oldest;
		if (_oldest == 8)
			_oldest = 0;
		std::cout << "Oldest contact will be replaced" << std::endl;
		insertionContact(_oldest);
	}
	else if (_index < 7)
	{
		++_index;
		insertionContact(_index);
	}
}
