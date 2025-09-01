/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:25:54 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/26 15:30:02 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAFORM_HPP
#define AAFORM_HPP

#define MAX 1
#define MIN 150

#define SUCCESS 0
#define SIGNED 2
#define PREVIOUSLY_SIGNED 3
#define NOT_SIGNED 4
#define NOT_EXECUTED 5

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		const std::string	_target;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;

	public:
		AForm();
		AForm(const std::string &name, const std::string &target,\
		const int &gradeToSign, const int &gradeToExec);
		AForm(const AForm &original);
		virtual ~AForm() = 0;

		AForm&	operator=(const AForm &original);

		std::string			getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;

		void				beSigned(const Bureaucrat &bur);
		void				checkToExecute(const Bureaucrat &executor) const;
		virtual void		execute(const Bureaucrat &executor) const = 0;

	class	GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	AlreadySigned: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	NotSigned: public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif
