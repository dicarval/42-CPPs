/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:04:27 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/26 15:02:14 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	Bureaucrat::GradeTooHighException()
{
	if (_grade == 1)
		std::cerr << _name << ": grade " << _grade <<\
		 " is already the Highest." << std::endl;
	else
		std::cerr << "Bureaucrat " << _name << ": invalid grade, grade " << _grade <<\
		 " is too High." << std::endl;
}

void	Bureaucrat::GradeTooLowException()
{
	if (_grade == 150)
		std::cerr << _name << ": grade " << _grade <<\
		 " is already the Lowest." << std::endl;
	else
		std::cerr << "Bureaucrat " << _name << ": invalid grade, grade " << _grade <<\
		 " is too Low." << std::endl;
}

void	AForm::GradeTooHighException()
{
	if (_gradeToSign < 1)
		std::cerr << "Form " << _name << ": invalid grade, grade to sign " <<\
		 _gradeToSign << " is too High." << std::endl;
	if (_gradeToExec < 1)
		std::cerr << "Form " << _name << ": invalid grade, grade to execute " <<\
		 _gradeToExec << " is too High." << std::endl;
}

void	AForm::GradeTooLowException()
{
	if (_gradeToSign > 150)
	std::cerr << "Form " << _name << ": invalid grade, grade to sign " <<\
	 _gradeToSign << " is too Low." << std::endl;
	if (_gradeToExec > 150)
		std::cerr << "Form " << _name << ": invalid grade, grade to execute " <<\
		 _gradeToExec << " is too Low." << std::endl;
}
