/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:03:41 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/12 18:16:56 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string		_name;
		int				_grade;

	public:
		Bureaucrat(const std::string &name, const int &grade);
		~Bureaucrat();

		void			GradeTooHighException();
		void			GradeTooLowException();
		void			IncrementGrade();
		void			DecrementGrade();
		void			signForm(Form &Form);
		std::string		getName() const;
		int				getGrade() const;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& Bureaucrat);

#endif
