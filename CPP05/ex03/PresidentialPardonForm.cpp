/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:43:44 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/01 16:36:16 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//CONSTRUCTORS & DESTRUCTOR
PresidentialPardonForm::PresidentialPardonForm()
	 : AForm("PresidentialPardonForm", "Default", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original)
 : AForm(original._name, original._target, original._gradeToSign, original._gradeToExec)
{
	*this = original;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

//OPERATORS
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &original)
{
	if (this != &original && original.getSigned() == true)
		_signed = original._signed;
	return (*this);
}

//MEMBER FUNCTIONS
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	std::cout << "* Multiple horns start to synchronized play *" << std::endl;
	std::cout << "* The bureaucrat " << executor.getName() << " appears and starts to read a decree *" << std::endl\
	 << "* \"In the name of Zaphod Beeblebrox, " << _target << " has been pardoned!\" *" << std::endl;
}
