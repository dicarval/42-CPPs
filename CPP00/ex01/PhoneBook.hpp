/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:17:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/12 17:25:17 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#define LOOP 1

class PhoneBook
{
	private:
		Contact			_contacts[8];
		unsigned int	_index;

	public:
		// constructor/destructor
		PhoneBook();
		~PhoneBook();

		void add();
		void search();
		void printPhoneBook();
		void printAllPhoneBookContacts();
		void printContact(int pos);
		void printColumn(std::string input);
};

#endif
