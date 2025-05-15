/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:13 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/15 14:34:41 by dicarval         ###   ########.fr       */
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
	num = std::atoi(index.c_str()) - 1;
	if (index[0] >= '1' && index[0] <= '8' && !index[1] && num <= _index)
		printSearch(num);
	else if (std::cin)
		std::cout << "Index is out of range or wrong." << std::endl;
	std::cout << std::endl << "Press Enter" << std::endl;
	std::getline(std::cin, index);
	if (!std::cin)
		return (insertion_stopped());
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
		insertionContact(++_index);
	if (std::cin)
		system("sleep 1");
}
