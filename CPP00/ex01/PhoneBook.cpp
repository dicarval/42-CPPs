/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:13 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/13 16:18:00 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_index = -1;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Exiting My Awesome PhoneBook" << std::endl;
}

void	PhoneBook::search()
{
	std::string	index;
	int			num;

	printPhoneBook();
	std::cout << "Please insert wanted Contact index: ";
	std::getline(std::cin, index);
	if (index[0] >= '1' && index[0] <= '8' && !index[1])
	{
		num = std::atoi(index.c_str()) - 1;
		if (num > _index)
		{
			std::cout << "Index is out of range or wrong.\n";
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

void	PhoneBook::insertion_stopped()
{
	std::cout << "Insertion stopped" << std::endl;
}

void	PhoneBook::add()
{
	_index += 1;
	if (_contacts[_index].addFirstName())
		return (insertion_stopped());
	if (_contacts[_index].addLastName())
		return (insertion_stopped());
	if (_contacts[_index].addNickname())
		return (insertion_stopped());
	if (_contacts[_index].addPhoneNum())
		return (insertion_stopped());
	if (_contacts[_index].addDarkSecret())
		return (insertion_stopped());
	std::cout << "Contact successly created" << std::endl;
}
