/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:19:02 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/01 19:13:13 by dicarval         ###   ########.fr       */
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
		{
			AForm *pp = new PresidentialPardonForm(formTarget);
			return (pp);
		}
		case 1:
		{
			AForm *rq = new RobotomyRequestForm(formTarget);
			return (rq);
		}
		case 2:
		{
			AForm *sc = new ShrubberyCreationForm(formTarget);
			return (sc);
		}
	}
	return (NULL);
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	std::string formsName[3] = {"presidential pardone", "robotomy request", "shrubbery creation"};

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (formName == formsName[i])
			{
				AForm *form = createForm(formTarget, i);
				std::cout << "Intern creates " << formName << std::endl;
				return (form);
			}
		}
		throw NameNotExist();
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception: while looking for " << formName << " the intern realized that " << e.what()  << std::endl;
		return (NULL);
	}
}
