/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:35:53 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/01 16:34:03 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//CONSTRUCTORS & DESTRUCTOR
AForm::AForm() : _name("Default"), _gradeToSign(150) ,_gradeToExec(150), _signed(false)
{}

AForm::AForm(const std::string &name, const std::string &target, const int &gradeToSign, const int &gradeToExec)
 : _name(name), _target(target), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	try
	{
		if (_gradeToSign > MIN || _gradeToExec > MIN)
			throw GradeTooLowException();
		else if (_gradeToSign < MAX || _gradeToExec < MAX)
			throw GradeTooHighException();
		std::cout << "Form " << _name << " has valid Grades" << " >> "\
		 << "starting instantiation!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Constructor exception: " << e.what() << std::endl;
	}
}

AForm::AForm(const AForm &original)
 : _name(original._name), _target(original._target), _gradeToSign(original._gradeToSign),\
 _gradeToExec(original._gradeToExec), _signed(false)
{}

AForm::~AForm()
{}

//OPERATORS
AForm&	AForm::operator=(const AForm &original)
{
	if (this != &original)
		_signed = original._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, const AForm &form)
{
	stream << form.getName() << "Form requires a grade to sign of " << form.getGradeToSign() <<\
	 " and requires a grade to execute of " << form.getGradeToExec() << " and it has ";
	if (form.getSigned() == false)
		stream << "not ";
	stream << "been signed" << std::endl;
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
void	AForm::beSigned(const Bureaucrat &bur)
{
	if (getSigned() == true)
		throw AlreadySigned();
	if (bur.getGrade() > getGradeToSign())
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
}

void	AForm::checkToExecute(const Bureaucrat &executor) const
{

	if (getSigned() == false)
		throw NotSigned();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
}
