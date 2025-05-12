/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:23:31 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/12 15:00:18 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
	public:
		std::string	_phone_num;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_dark_secret;

		// constructor/destructor
		Contact() {};
		~Contact() {};

		//adders
		void		addFirstName(std::string _first_name);
		void		addLastName(std::string _last_name);
		void		addNickName(std::string _nickname);
		void		addPhoneNum(std::string _phone_num);
		void		addDarkSecret(std::string _dark_secret);

		//searchers
		std::string	searchFirstName();
		std::string	searchLastName();
		std::string	searchNickname();
		std::string	searchPhoneNum();
		std::string	searchDarkSecret();


};

#endif
