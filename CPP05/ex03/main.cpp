/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:59:43 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/03 11:54:20 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	InternTest(Bureaucrat &good, Bureaucrat &bad)
{
	Intern someRandomIntern;
	std::cout << "\n----- Intern Test -----\n\n";
	AForm* blah = NULL;
	AForm* bruh = NULL;
	AForm* rrf = NULL;

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		good.executeForm(*rrf);
		good.signForm(*rrf);
		good.executeForm(*rrf);
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception: the intern realized that " << e.what()  << std::endl;
	}

	try
	{
		blah = someRandomIntern.makeForm ("blah", "the Universe");
		good.signForm(*blah);
		good.executeForm(*blah);
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception: the intern realized that " << e.what()  << std::endl;
	}

	try
	{
		bruh = someRandomIntern.makeForm ("Bruh", "the Moon");
		bad.signForm(*bruh);
		bad.executeForm(*bruh);
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception: the intern realized that " << e.what()  << std::endl;
	}

	if (rrf)
		delete rrf;
	if (blah)
		delete blah;
	if (bruh)
		delete bruh;
}

void	ShrubberyCreationForm_test(Bureaucrat &good, Bureaucrat &bad)
{
	std::cout << "\n----- Shrubbery Creation Form -----\n\n";

	ShrubberyCreationForm	form("Churrasqueira");
	bad.signForm(form);
	good.executeForm(form);
	good.signForm(form);
	bad.executeForm(form);
	good.executeForm(form);
}

void	RobotomyRequestForm_test(Bureaucrat &good, Bureaucrat &bad)
{
	std::cout << "\n----- Robotomy Request Form -----\n\n";

	RobotomyRequestForm	form("Sheldon");
	bad.signForm(form);
	good.executeForm(form);
	good.signForm(form);
	bad.executeForm(form);
	good.executeForm(form);
	good.executeForm(form);
	good.executeForm(form);
}

void	PresidentialPardonForm_test(Bureaucrat &good, Bureaucrat &bad)
{
	std::cout << "\n----- Presidential Pardon Form -----\n\n";

	PresidentialPardonForm	form("Socrates");
	bad.signForm(form);
	good.executeForm(form);
	good.signForm(form);
	bad.executeForm(form);
	good.executeForm(form);
}

int main()
{
	Bureaucrat Alberto("Alberto", 1);
	Bureaucrat Ulisses("Ulisses", 150);
	std::cout << "\n\n----- Initial values -----\n\n";
	std::cout << Alberto;
	std::cout << Ulisses;

	Alberto.incrementGrade();
	Ulisses.decrementGrade();

	InternTest(Alberto, Ulisses);
	ShrubberyCreationForm_test(Alberto, Ulisses);
	RobotomyRequestForm_test(Alberto, Ulisses);
	PresidentialPardonForm_test(Alberto, Ulisses);
}
