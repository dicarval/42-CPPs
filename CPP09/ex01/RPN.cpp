/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:18:34 by dicarval          #+#    #+#             */
/*   Updated: 2025/11/13 21:13:35 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//CONSTRUCTORS & DESTRUCTOR
RPN::RPN()
{}

RPN::RPN(const RPN &original)
{
	*this = original;
}

RPN::~RPN()
{}

//OPERATORS
RPN&	RPN::operator=(const RPN &original)
{
	if(this != &original)
		this->_args = original._args;
	return (*this);
}

//MEMBER FUNCTIONS
void	RPN::performTheMagic()
{
	long temp;
	std::list<int> rpn;
	std::list<char>::iterator it = _args.begin();
	while (it != _args.end())
	{
		if (std::isdigit(*it))
			rpn.push_front(static_cast<int>(*(it++) - '0'));
		else
		{
			while (rpn.size() != 1)
			{
				std::list<int>::iterator itrpn = rpn.begin();
				int arithmeticOp = *(it++);
				temp = *(itrpn++);
				if (arithmeticOp == '*')
						*itrpn = *itrpn * temp;
				else if (arithmeticOp == '+')
						*itrpn = *itrpn + temp;
				else if (arithmeticOp == '-')
						*itrpn = *itrpn - temp;
				else if (arithmeticOp == '/')
						*itrpn = *itrpn / temp;
				rpn.pop_front();
			}
		}
	}
	std::cout << *rpn.begin() << std::endl;
}

void	RPN::convertToList(const std::string &input)
{
	for (unsigned int i = 0; input.find(input[i]) != std::string::npos; i++)
	{
		if (input[i] != ' ')
			_args.push_back(input[i]);
	}
	unsigned int digits = 0;
	unsigned int operators = 0;
	for (std::list<char>::const_iterator it = _args.begin(); it != _args.end(); ++it)
	{
		if (std::isdigit(*it))
			digits++;
		else
			operators++;
	}
	if (digits != operators + 1)
		throw InvalidInput();
}

//EXCEPTIONS
const char*	RPN::InvalidInput::what() const throw()
{
	return ("invalid input introduced");
}
