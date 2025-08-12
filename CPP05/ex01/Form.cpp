/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:35:53 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/12 18:23:35 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//CONSTRUCTORS & DESTRUCTOR
Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExec) : \
_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	try
	{
		if (_gradeToSign > MIN || _gradeToExec > MIN)
			throw (101);
		else if (_gradeToSign < MAX || _gradeToExec < MAX)
			throw (505);
		else
			std::cout << "Valid Grades, starting instantiation!" << std::endl;
	}
	catch (int &e)
	{
		if (e == 505)
			GradeTooHighException();
		else
			GradeTooLowException();
	}
}

Form::~Form()
{}

//OPERATORS
std::ostream&	operator<<(std::ostream &stream, const Form &Form)
{
	stream << Form.getName() << ", bureaucrat grade to sign " << Form.getGradeToSign() <<\
	 "and grade to execute " << Form.getGradeToExec();
	return (stream);
}

int	Form::beSigned(const Bureaucrat &Bur)
{
	if (getSigned() == true)
		return (PREVIOUSLY_SIGNED);
	try
	{
		if (Bur.getGrade() <= getGradeToSign())
		{
			_signed = true;
			return (SIGNED);
		}
		else
			throw (101);
	}
	catch (int &e)
	{
		GradeTooLowException();
		return (NOT_SIGNED);
	}
}

//GETTERS
std::string	Form::getName() const
{
	return(_name);
}

bool	Form::getSigned() const
{
	return(_signed);
}

int	Form::getGradeToSign() const
{
	return(_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return(_gradeToExec);
}
