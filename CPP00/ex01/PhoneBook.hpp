/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:17:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/14 11:27:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_oldest;

	public:
		//constructor/destructor
		PhoneBook();
		~PhoneBook();

		void	add();
		void	insertionContact(int pos);
		void	search();
		void	printPhoneBook();
		void	printAllPhoneBookContacts();
		void	printContact(int pos);
		void	printColumn(std::string input);
		void	insertion_stopped();
};

#endif
