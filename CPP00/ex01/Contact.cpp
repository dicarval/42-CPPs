/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:38:12 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/13 16:39:01 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	Contact::addFirstName()
{
	int	i = -1;

	std::cout << "Add first name: ";
	while(++i)
	{
		if (i == 0)
			std::getline(std::cin, _first_name);
		if (!std::cin)
			return (UNSUCCESS);
		if (!_first_name[0])
		{
			std::cout << "Empty field, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_first_name[i] == '\t')
		{
			std::cout << "TAB not allowed, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_first_name[i])
			continue ;
		break ;
	}
	std::cout << "INSERTED" << std::endl;
	return (SUCCESS);
}

int	Contact::addLastName()
{
	int	i = -1;

	std::cout << "Add last name: ";
	while(++i)
	{
		if (i == 0)
			std::getline(std::cin, _last_name);
		if (!std::cin)
			return (UNSUCCESS);
		if (!_last_name[0])
		{
			std::cout << "Empty field, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_last_name[i] == '\t')
		{
			std::cout << "TAB not allowed, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_last_name[i])
			continue ;
		break ;
	}
	std::cout << "INSERTED" << std::endl;
	return (SUCCESS);
}

int	Contact::addNickname()
{
	int	i = -1;

	std::cout << "Add nickname: ";
	while(++i)
	{
		if (i == 0)
			std::getline(std::cin, _nickname);
		if (!std::cin)
			return (UNSUCCESS);
		if (!_nickname[0])
		{
			std::cout << "Empty field, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_nickname[i] == '\t')
		{
			std::cout << "TAB not allowed, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_nickname[i])
			continue ;
		break ;
	}
	std::cout << "INSERTED" << std::endl;
	return (SUCCESS);
}

int	Contact::addPhoneNum()
{
	int i = -1;

	std::cout << "Add phone number: ";
	while (++i)
	{
		if (i == 0)
			std::getline(std::cin, _phone_num);
		if (!std::cin)
			return (UNSUCCESS);
		if (!_phone_num[0])
		{
			std::cout << "Empty field, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_phone_num[i] && (_phone_num[i] < '0' || _phone_num[i] > '9'))
		{
			std::cout << "Input different of numbers, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_phone_num[i] >= '0' && _phone_num[i] <= '9')
			continue ;
		break ;
	}
	std::cout << "INSERTED" << std::endl;
	return (SUCCESS);
}

int	Contact::addDarkSecret()
{
	int	i = -1;

	std::cout << "Add Dark secret: ";
	while(++i)
	{
		if (i == 0)
			std::getline(std::cin, _dark_secret);
		if (!std::cin)
			return (UNSUCCESS);
		if (!_dark_secret[0])
		{
			std::cout << "Empty field, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_dark_secret[i] == '\t')
		{
			std::cout << "TAB not allowed, try again" << std::endl;
			i = -1;
			continue ;
		}
		else if (_dark_secret[i])
			continue ;
		break ;
	}
	std::cout << "INSERTED" << std::endl;
	return (SUCCESS);
}

std::string	Contact::searchFirstName()
{
	return (_first_name);
}

std::string	Contact::searchLastName()
{
	return (_last_name);
}

std::string	Contact::searchPhoneNum()
{
	return (_phone_num);
}

std::string	Contact::searchNickname()
{
	return (_nickname);
}

std::string	Contact::searchDarkSecret()
{
	return (_nickname);
}
