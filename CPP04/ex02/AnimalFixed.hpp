/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimalFixed.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:49:08 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 17:25:54 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALFIXED_HPP
#define ANIMALFIXED_HPP

#include <iostream>

class AnimalFixed
{
	protected:
		std::string _type;

	public:
		AnimalFixed();
		AnimalFixed(const AnimalFixed& original);
		virtual ~AnimalFixed() = 0;

		AnimalFixed&			operator=(const AnimalFixed &original);

		std::string		getType() const;

		virtual void	makeSound() const = 0;
};

#endif
