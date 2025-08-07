/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:28:50 by dicarval          #+#    #+#             */
/*   Updated: 2025/08/07 15:05:38 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria	*_inventory[4];
		std::string	_name;

		bool				_checkInvSpace(int idx);
		bool				_checkInvSlot(int idx);

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &original);
		~Character();

		Character&			operator=(const Character &original);

		void				setName(const std::string &newName);

		const std::string&	getName() const;

		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);


};

#endif
