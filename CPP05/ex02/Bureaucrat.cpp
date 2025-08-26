/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:40:25 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/26 18:01:35 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//CONSTRUCTORS & DESTRUCTOR
Bureaucrat::Bureaucrat() : _name("Manel"), _grade(150)
{}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name), _grade(grade)
{
	try
	{
		if (_grade > 150)
			throw (101);
		else if (_grade < 1)
			throw (505);
		else
			std::cout << "Valid Grade from " << _name << " >> " << _grade <<\
			 ", starting instantiation!" << std::endl;
	}
	catch (int &e)
	{
		if (e == 505)
			GradeTooHighException();
		else
			GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &original) : _name(original._name)
{
	*this = original;
}

Bureaucrat::~Bureaucrat()
{}

//OPERATORS
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &original)
{
	_grade = original._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &bur)
{
	stream << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return (stream);
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

//MEMBER FUNCTIONS
void	Bureaucrat::IncrementGrade()
{
	try
	{
		if ((_grade - 1) < 1)
			throw (505);
		else
		{
			_grade--;
			std::cout << "Grade Incremented >> " << *this;
		}
	}
	catch (int &e)
	{
		std::cerr << "Grade Incremented >> ";
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
			std::cout << "Grade Decremented >> " << *this;
		}
	}
	catch (int &e)
	{
		std::cerr << "Grade Decremented >> ";
		GradeTooLowException();
	}
}

void	Bureaucrat::signForm(AForm &Form)
{
	int sign_status;

	sign_status = Form.beSigned(*this);
	if (sign_status == SIGNED)
		std::cout << _name << " signed " << Form.getName() <<"." << std::endl;
	else
	{
		std::cout << _name << " couldn't sign " << Form.getName() << " because ";
		if (sign_status == NOT_SIGNED)
			std::cout << _name << " is not qualified enough to sign it." << std::endl;
		else
			std::cout << "the form is already signed." << std::endl;
	}
}
