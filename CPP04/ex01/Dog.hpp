/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:31:39 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 15:49:21 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _processor;

	public:
		Dog();
		Dog(const Dog& original);
		~Dog();

		Dog&		operator=(const Dog& original);

		void		setDogIdea(std::string idea, unsigned int index);

		std::string	getDogIdea(unsigned int index) const;
		Brain*		getDogBrain() const;

		void		makeSound() const override;
		void		printDogIdeas(unsigned int first, unsigned int last);
};

#endif
