/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:35:53 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/01 15:00:57 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//CONSTRUCTORS & DESTRUCTOR
Form::Form() : _name("Default"), _gradeToSign(150) ,_gradeToExec(150), _signed(false)
{}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExec)
 : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	try
	{
		if (_gradeToSign > MIN || _gradeToExec > MIN)
			throw GradeTooLowException();
		else if (_gradeToSign < MAX || _gradeToExec < MAX)
			throw GradeTooHighException();
		std::cout << "Form " << _name << " has a valid Grades" << " >> "\
		 << "starting instantiation!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Constructor exception: " << e.what() << std::endl;
	}
}

Form::Form(const Form &original)
 : _name(original._name), _gradeToSign(original._gradeToSign),\
 _gradeToExec(original._gradeToExec), _signed(false)
{}

Form::~Form()
{}

//OPERATORS
Form&	Form::operator=(const Form &original)
{
	if (this != &original)
		_signed = original._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, const Form &form)
{
	stream << form.getName() << ", bureaucrat expected grade to sign " << form.getGradeToSign() <<\
	 "and expected grade to execute " << form.getGradeToExec();
	return (stream);
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

//MEMBER FUNCTIONS
int	Form::beSigned(const Bureaucrat &bur)
{
	try
	{
		if (getSigned() == true)
			return (PREVIOUSLY_SIGNED);
		if (bur.getGrade() <= getGradeToSign())
		{
			_signed = true;
			return (SIGNED);
		}
		else
			throw GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << "beSigned exception: " << e.what() << std::endl;
		return (NOT_SIGNED);
	}
}
