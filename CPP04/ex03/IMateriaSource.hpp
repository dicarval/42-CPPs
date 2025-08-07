/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:23:16 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/07 15:03:33 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		//CONSTRUCTOR & DESTRUCTOR
		virtual ~IMateriaSource() {};

		//MEMBER FUNCTIONS
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};

#endif
