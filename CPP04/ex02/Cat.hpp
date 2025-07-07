/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:00:51 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/04 11:12:36 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AnimalFixed.hpp"
#include "Brain.hpp"

class Cat : public AnimalFixed
{
	private:
		Brain* _processor;

	public:
		Cat();
		Cat(const Cat& original);
		~Cat();

		Cat&		operator=(const Cat &original);

		void		setCatIdea(std::string idea, unsigned int index);

		std::string	getCatIdea(unsigned int index) const;
		Brain*		getCatBrain() const;

		void		makeSound() const;
		void		printCatIdeas(unsigned int first, unsigned int last);
};

#endif
