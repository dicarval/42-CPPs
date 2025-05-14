/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addPhoneBook.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:24:14 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/14 11:36:39 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::insertionContact(int pos)
{
	if (_contacts[pos].addFirstName())
		return (insertion_stopped());
	if (_contacts[pos].addLastName())
		return (insertion_stopped());
	if (_contacts[pos].addNickname())
		return (insertion_stopped());
	if (_contacts[pos].addPhoneNum())
		return (insertion_stopped());
	if (_contacts[pos].addDarkSecret())
		return (insertion_stopped());
	std::cout << "Contact successly created" << std::endl;
}
