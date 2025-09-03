/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:19:45 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/03 11:17:30 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//CONSTRUCTORS & DESTRUCTOR
RobotomyRequestForm::RobotomyRequestForm()
	 : AForm("RobotomyRequestForm", "Default", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original)
 : AForm(original._name, original._target, original._gradeToSign, original._gradeToExec)
{
	*this = original;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

//OPERATORS
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
	if (this != &original && original.getSigned() == true)
		_signed = original._signed;
	return (*this);
}

//MEMBER FUNCTIONS
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	std::cout << "* BZZZZZZZZZZZZZZZZZ * - Drilling noises" << std::endl;
	if (std::rand() % 2)
		std::cout << "* " << _target << " has been robotomized successfully by " <<\
		 executor.getName() << "! *" << std::endl;
	else
		std::cout << "* Robotomy failed on " << _target << "!*" << std::endl;
}
