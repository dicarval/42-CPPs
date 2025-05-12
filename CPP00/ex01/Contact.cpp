/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:38:12 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/12 16:15:43 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::addFirstName(std::string first_name)
{
	std::cout << "Add first name: ";
	std::getline(std::cin, first_name);
}

void	Contact::addLastName(std::string last_name)
{
	std::cout << "Add last name: ";
	std::getline(std::cin, last_name);
}

void	Contact::addNickName(std::string nick_name)
{
	std::cout << "Add nickname: ";
	std::getline(std::cin, nick_name);
}

void	Contact::addPhoneNum(std::string phone_num)
{
	std::cout << "Add phone number: ";
	std::getline(std::cin, phone_num);
}

void	Contact::addDarkSecret(std::string dark_secret)
{
	std::cout << "Add Dark secret: ";
	std::getline(std::cin, dark_secret);
}
