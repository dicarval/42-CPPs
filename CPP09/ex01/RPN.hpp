/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:41:05 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/11 16:26:20 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <iostream>
#include <sstream>
//#include <string>

class RPN
{
	private:
		std::list<char>	_args;

	public:
		RPN();
		RPN(const RPN &original);
		~RPN();


};

#endif
