/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:25:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/12 18:20:11 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#define MAX 1
#define MIN 150
#define SIGNED 2
#define PREVIOUSLY_SIGNED 3
#define NOT_SIGNED 4

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;

	public:
		Form(const std::string &name, const int &gradeToSign, const int &gradeToExec);
		~Form();

		void				GradeTooHighException();
		void				GradeTooLowException();
		int					beSigned(const Bureaucrat &Bur);
		std::string			getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
};

#endif
