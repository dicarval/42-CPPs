/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:04:27 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/03 13:42:15 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("the Bureaucrat grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("the Bureaucrat grade is too low");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("the Form grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("the Form grade is too low");
}

const char*	AForm::AlreadySigned::what() const throw()
{
	return ("the Form is already signed");
}

const char*	AForm::NotSigned::what() const throw()
{
	return ("the Form is not signed");
}

const char*	Intern::NameNotExist::what() const throw()
{
	return ("the Form doesn't exist");
}
