/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:40:25 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/03 13:39:49 by dicarval         ###   ########.fr       */
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
		if (_grade > MIN)
			throw GradeTooLowException();
		if (_grade < MAX)
			throw GradeTooHighException();
		std::cout << "Bureaucrat " << _name << " has a valid Grade" << " >> "\
		 << _grade << ", starting instantiation!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Constructor exception (" << _name << "): "\
		 << e.what() << std::endl;
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
	if (this != &original)
		_grade = original._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &bur)
{
	stream << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "."\
	 << std::endl;
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

//MEMBERS FUNCTIONS
void	Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade == MAX)
			throw GradeTooHighException();
		_grade--;
		std::cout << "Grade Incremented >> " << *this;
	}
	catch (std::exception &e)
	{
		std::cerr << "Grade incrementing exception (" << _name << "): "\
		 << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade == MIN)
			throw GradeTooLowException();
		_grade++;
		std::cout << "Grade Decremented >> " << *this;
	}
	catch (std::exception &e)
	{
		std::cerr << "Grade decrementing exception (" << _name << "): "\
		 << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(Form &form)
{
	int sign_status;

	sign_status = form.beSigned(*this);
	if (sign_status == SIGNED)
		std::cout << _name << " signed " << form.getName() <<"." << std::endl;
	else
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because ";
		if (sign_status == NOT_SIGNED)
			std::cout << _name << " is not qualified enough to sign it." << std::endl;
		else
			std::cout << "the form is already signed." << std::endl;
	}
}
