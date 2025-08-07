/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:16:58 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/07 15:06:36 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(const AMateria &original);
		AMateria(const std::string &type);
		virtual ~AMateria() = 0;

		AMateria&			operator=(const AMateria &original);

		const std::string&	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter &target);
};


#endif
