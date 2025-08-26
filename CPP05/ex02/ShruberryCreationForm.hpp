/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:40:13 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/26 15:29:46 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShruberryCreationForm : public AForm
{
	private:
		const std::string	_fileName;

	public:
		ShruberryCreationForm(std::string target);
		~ShruberryCreationForm();

		int	execute(const Bureaucrat &executor);
};

#endif
