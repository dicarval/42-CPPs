/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:04:27 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/01 14:27:54 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("the Bureaucrat grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("the Bureaucrat grade is too low");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("the Form grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("the Form grade is too low");
}
