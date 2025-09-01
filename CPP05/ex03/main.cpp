/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:59:43 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/01 19:12:48 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
		Intern someRandomIntern;
		std::cout << "\n\n----- Initial values -----\n\n";
		std::cout << Alberto;
		std::cout << Ulisses;

		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* blah = someRandomIntern.makeForm ("blah", "the Universe");

		Alberto.executeForm(*rrf);
		Alberto.signForm(*rrf);
		Alberto.executeForm(*rrf);
		Alberto.signForm(*blah);
		Alberto.executeForm(*blah);

		Alberto.incrementGrade();
		Ulisses.decrementGrade();

		ShrubberyCreationForm_test(Alberto, Ulisses);
		RobotomyRequestForm_test(Alberto, Ulisses);
		PresidentialPardonForm_test(Alberto, Ulisses);
}
