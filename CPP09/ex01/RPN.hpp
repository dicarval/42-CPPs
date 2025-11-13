/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:41:05 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/13 20:40:16 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstring>
//#include <string>

class RPN
{
	private:
		std::list<char>	_args;

	public:
		RPN();
		RPN(const RPN &original);
		~RPN();

		RPN&	operator=(const RPN &original);

		void	convertToList(const std::string &input);
		void	performTheMagic();

		class InvalidInput : public std::exception
		{
				virtual const char* what() const throw();
		};

};

#endif
