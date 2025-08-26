/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:03:41 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/26 18:02:00 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string		_name;
		int				_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &original);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat &original);

		void			GradeTooHighException();
		void			GradeTooLowException();
		void			IncrementGrade();
		void			DecrementGrade();
		void			signForm(AForm &Form);
		std::string		getName() const;
		int				getGrade() const;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bur);

#endif
