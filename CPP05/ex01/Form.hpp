/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:25:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/09/01 14:21:54 by dicarval         ###   ########.fr       */
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
		Form();
		Form(const std::string &name, const int &gradeToSign, const int &gradeToExec);
		Form(const Form &original);
		~Form();

		Form&	operator=(const Form &original);

		std::string			getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;

		int					beSigned(const Bureaucrat &bur);

	class	GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &stream, const Form &form);

#endif
