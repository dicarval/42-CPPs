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
		std::string			_name;
		int					_gradeToSign;
		int					_gradeToExec;
		bool				_signed;

	public:
		AForm();
		AForm(const std::string &name, const int &gradeToSign, const int &gradeToExec);
		AForm(const AForm &original);
		virtual ~AForm() = 0;

		AForm&	operator=(const AForm &original);

		void				GradeTooHighException();
		void				GradeTooLowException();
		int					beSigned(const Bureaucrat &bur);
		int					checkToExecute(const Bureaucrat &executor);
		virtual int			execute(const Bureaucrat &executor) = 0;
		std::string			getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
};

#endif
