/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:17:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/07 17:01:40 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact			contacts[8];
		unsigned int	index;

	public:
		PhoneBook();
		~PhoneBook();

		void add();
		void search();
		void printContact();
		void printPhoneBook();
		void printAllPhoneBookContacts();




};



#endif
