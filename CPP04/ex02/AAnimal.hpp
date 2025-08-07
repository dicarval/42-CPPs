/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:49:08 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/17 13:52:06 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(const AAnimal& original);
		virtual ~AAnimal() = 0;

		AAnimal&	operator=(const AAnimal &original);

		std::string		getType() const;

		virtual void	makeSound() const = 0;
};

#endif
