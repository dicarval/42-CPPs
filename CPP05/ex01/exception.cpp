/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:04:27 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/12 18:30:56 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	Bureaucrat::GradeTooHighException()
{
	std::cout << "Bureaucrat: invalid Grade, Grade " << _grade << " is too High." <<\
	 std::endl;
}

void	Bureaucrat::GradeTooLowException()
{
	std::cout << "Bureaucrat: invalid Grade, Grade " << _grade << " is too Low." <<\
	 std::endl;
}

void	Form::GradeTooHighException()
{
	if (_gradeToSign < 1)
		std::cout << "Form: invalid Grade, Grade to sign " << _gradeToSign <<\
		 " is too High." << std::endl;
	if (_gradeToExec < 1)
		std::cout << "Form: invalid Grade, Grade to execute " << _gradeToSign <<\
		 " is too High." << std::endl;
}

void	Form::GradeTooLowException()
{
	if (_gradeToSign > 150)
	std::cout << "Form: invalid Grade, Grade to sign " << _gradeToSign <<\
	 " is too Low." << std::endl;
	if (_gradeToExec > 150)
		std::cout << "Form: invalid Grade, Grade to execute " << _gradeToExec <<\
		 " is too Low." << std::endl;
}
