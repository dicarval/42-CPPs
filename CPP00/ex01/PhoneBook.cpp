/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:13 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/12 17:30:50 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_index = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Exiting PhoneBook" << std::endl;
}

void	PhoneBook::search()
{
	std::string	index;
	int			num;

	printPhoneBook();
	std::getline(std::cin, index);
	if (index[0] >= '1' && index[0] <= '8' && !index[1])
		num = std::atoi(index.c_str());
	else
		std::cout << "Index is out of range or wrong.\n";

}

void	PhoneBook::add()
{
	_contacts[_index].addFirstName(_contacts[_index]._first_name);
	_contacts[_index].addLastName(_contacts[_index]._last_name);
	_contacts[_index].addNickName(_contacts[_index]._nickname);
	_contacts[_index].addPhoneNum(_contacts[_index]._phone_num);
	_contacts[_index].addDarkSecret(_contacts[_index]._dark_secret);
}
