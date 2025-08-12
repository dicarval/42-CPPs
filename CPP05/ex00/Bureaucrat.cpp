/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:40:25 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/12 18:33:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//CONSTRUCTORS & DESTRUCTOR
Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name), _grade(grade)
{
	try
	{
		if (_grade > 150)
			throw (101);
		else if (_grade < 1)
			throw (505);
		else
			std::cout << "Valid Grade >> " << _grade << ", starting instantiation!" << std::endl;
	}
	catch (int &e)
	{
		if (e == 505)
			GradeTooHighException();
		else
			GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat()
{}

//OPERATORS
std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &Bureaucrat)
{
	stream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << ".";
	return (stream);
}

void	Bureaucrat::IncrementGrade()
{
	try
	{
		if ((_grade - 1) < 1)
			throw (505);
		else
		{
			_grade--;
			std::cout << "Grade Incremented >> " << *this << std::endl;
		}
	}
	catch (int &e)
	{
		GradeTooHighException();
	}
}

void	Bureaucrat::DecrementGrade()
{
	try
	{
		if ((_grade + 1) > 150)
			throw (101);
		else
		{
			_grade++;
			std::cout << "Grade Decremented >> " << *this << std::endl;
		}
	}
	catch (int &e)
	{
		GradeTooLowException();
	}
}

//GETTERS
std::string	Bureaucrat::getName() const
{
	return(_name);
}

int	Bureaucrat::getGrade() const
{
	return(_grade);
}
