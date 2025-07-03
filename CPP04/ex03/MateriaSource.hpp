/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:09:49 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/03 17:29:50 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		learnedMateria[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& original);
		~MateriaSource();



		void			learnMateria(AMateria*) = 0;
		AMateria*		createMateria(std::string const & type);
};

#endif
