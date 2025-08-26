/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:35:53 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/26 18:03:53 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//CONSTRUCTORS & DESTRUCTOR
AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150) ,_gradeToExec(150)
{}

AForm::AForm(const std::string &name, const int &gradeToSign, const int &gradeToExec) : \
_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	try
	{
		if (_gradeToSign > MIN || _gradeToExec > MIN)
			throw (101);
		else if (_gradeToSign < MAX || _gradeToExec < MAX)
			throw (505);
		else
			std::cout << "Valid Grades from " << _name << ", starting instantiation!"\
			 << std::endl;
	}
	catch (int &e)
	{
		if (e == 505)
			GradeTooHighException();
		else
			GradeTooLowException();
	}
}

AForm::AForm(const AForm &original)
: _name(original._name), _signed(false),\
 _gradeToSign(original._gradeToSign), _gradeToExec(original._gradeToExec)
{}

AForm::~AForm()
{}

//OPERATORS
AForm&	AForm::operator=(const AForm &original)
{
	_signed = original._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, const AForm &form)
{
	stream << form.getName() << ", bureaucrat expected grade to sign " << form.getGradeToSign() <<\
	 "and expected grade to execute " << form.getGradeToExec();
	return (stream);
}

//GETTERS
std::string	AForm::getName() const
{
	return(_name);
}

bool	AForm::getSigned() const
{
	return(_signed);
}

int	AForm::getGradeToSign() const
{
	return(_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return(_gradeToExec);
}

//MEMBER FUNCTIONS
int	AForm::beSigned(const Bureaucrat &bur)
{
	if (getSigned() == true)
		return (PREVIOUSLY_SIGNED);
	try
	{
		if (bur.getGrade() <= getGradeToSign())
		{
			_signed = true;
			return (SIGNED);
		}
		else
			throw (101);
	}
	catch (const int &e)
	{
		GradeTooLowException();
		return (NOT_SIGNED);
	}
}

int	AForm::checkToExecute(const Bureaucrat &executor)
{
	try
	{
		if (getSigned() == false)
			throw (202);
		if (executor.getGrade() > getGradeToExec())
			throw (303);
		else
			return (SUCCESS);
	}
	catch(const int &e)
	{
		if (e == 202)
			return (std::cerr << "The " << _name << " form is not signed" <<\
			 std::endl, NOT_SIGNED);
		else
			return (std::cerr << "The bureaucrat " <<\
			 executor.getName() << "has not enough grade to execute "<<\
			 _name << std::endl, NOT_EXECUTED);
	}
}
