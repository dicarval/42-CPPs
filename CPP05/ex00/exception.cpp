/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:04:27 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/12 15:52:37 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	Bureaucrat::GradeTooHighException()
{
	std::cout << "Invalid Grade, Grade " << _grade << " is too High." <<\
	 std::endl;
}

void	Bureaucrat::GradeTooLowException()
{
	std::cout << "Invalid Grade, Grade " << _grade << " is too Low." <<\
	 std::endl;
}
