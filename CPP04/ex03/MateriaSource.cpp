/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:23:21 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/17 15:46:18 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//CONSTRUCTORS & DESTRUCTOR

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		_learnedMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& original)
{
	for (int i = 0; i < 4; i++)
		_learnedMateria[i] = NULL;
	*this = original;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_learnedMateria[i])
			delete _learnedMateria[i];
	}
}

//OPERATOR

MateriaSource&	MateriaSource::operator=(const MateriaSource& original)
{
	for (int i = 0; i < 4; i++)
	{
		if(_learnedMateria[i])
			delete _learnedMateria[i];
		_learnedMateria[i] = NULL;
		if (original._learnedMateria[i])
			_learnedMateria[i] = original._learnedMateria[i]->clone();
	}
	return (*this);
}

//MEMBER FUNCTIONS

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << "Materia Source > ! There is no Materia to be learnt!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_learnedMateria[i] == NULL)
		{
			_learnedMateria[i] = materia;
			std::cout << "Materia Source > * Learnt \"" << materia->getType() << "\" Materia *" << std::endl;
			return ;
		}
		else if (i == 3)
		{
			std::cout << "Materia Source > ! There is no space to learn more Materias !" << std::endl;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for(int i = 0; i < 4; i++)
	{
		if(_learnedMateria[i] && type == _learnedMateria[i]->getType())
		{
			std::cout << "Materia Source > * Created \"" << type << "\" Materia *" << std::endl;
			return(_learnedMateria[i]->clone());
		}
	}
	std::cout << "Materia Source > ! No Materia of type \"" << type << "\" was learnt !" << std::endl;
	return (NULL);
}
