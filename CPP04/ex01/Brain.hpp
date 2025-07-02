/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:01:17 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/02 15:21:25 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& original);
		~Brain();

		Brain&		operator=(const Brain& original);

		void		setIdea(std::string idea, unsigned int index);

		std::string	getIdea(unsigned int index) const;

		void		printIdeas(unsigned int first, unsigned int last);
};


#endif
