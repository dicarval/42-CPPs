/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:19:02 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/03 13:57:33 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//CONSTRUCTORS & DESTRUCTOR
Intern::Intern()
{}

Intern::Intern(const Intern &original)
{
	*this = original;
}

Intern::~Intern()
{}

//OPERATORS
Intern&	Intern::operator=(const Intern &original)
{
	(void)original;
	return (*this);
}

//MEMBER FUNCTIONS
AForm* Intern::createForm(const std::string &formTarget, int &formNumber)
{

	switch (formNumber)
	{
		case 0:
			return (new PresidentialPardonForm(formTarget));
		case 1:
			return (new RobotomyRequestForm(formTarget));
		case 2:
			return (new ShrubberyCreationForm(formTarget));
	}
	return (NULL);
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	std::string formsName[3] = {"presidential pardone", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formsName[i])
		{
			AForm *form = createForm(formTarget, i);
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (form);
		}
	}
	throw NameNotExist();
}
