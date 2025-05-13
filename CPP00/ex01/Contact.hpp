/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:23:31 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/13 16:39:19 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

#define UNSUCCESS 1
#define SUCCESS 0

#define LOOP 1

class Contact
{
	public:
		std::string	_phone_num;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_dark_secret;

		//constructor/destructor
		Contact()	{};
		~Contact()	{};

		//adders
		int			addFirstName();
		int			addLastName();
		int			addNickname();
		int			addPhoneNum();
		int			addDarkSecret();

		//searchers
		std::string	searchFirstName();
		std::string	searchLastName();
		std::string	searchNickname();
		std::string	searchPhoneNum();
		std::string	searchDarkSecret();


};

#endif
