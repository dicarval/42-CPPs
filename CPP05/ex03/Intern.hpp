/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:18:12 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/03 11:44:29 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &original);
		~Intern();

		Intern& operator=(const Intern &original);

		AForm*	makeForm(const std::string &formName, const std::string &formTarget);
		AForm*	createForm(const std::string &formTarget, int &formNumber);

	class	NameNotExist: public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif
