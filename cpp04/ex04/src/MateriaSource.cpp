/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:15:35 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/27 04:39:38 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "\e[2mDefault constructor MateriaSource called\e[0m" << std::endl;
	for (int i = 0; i < MAX_SPELL; i++)
		_bookOfSpells[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	(void)other;
	std::cout << "\e[2mCopy constructor MateriaSource called\e[0m" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource()
{
	std::cout << "\e[2mDestructor MateriaSource called\e[0m" << std::endl;
	for (int i = 0; i < MAX_SPELL; i++)
	{
		if (this->_bookOfSpells[i])
			delete this->_bookOfSpells[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "\e[2mAssignation operator MateriaSource called\e[0m" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < MAX_SPELL; i++)
	{
		if (_bookOfSpells[i])
			delete _bookOfSpells[i];
		_bookOfSpells[i] = other._bookOfSpells[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *newMat)
{
	if (!newMat)
		return ;
	for (int i = 0; i < MAX_SPELL; i++)
	{
		if (this->_bookOfSpells[i] == newMat)
		{
			std::cout << newMat->getType() << " already learned" << std::endl;
			return ;
		}
		if (!this->_bookOfSpells[i])
		{
			this->_bookOfSpells[i] = newMat;
			std::cout << "Learned " << newMat->getType() << std::endl;
			return ;
		}
	}
	std::cout << "The book of spells is full, can't learn more spells" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_SPELL; i++)
	{
		if (this->_bookOfSpells[i] && this->_bookOfSpells[i]->getType() == type)
			return (this->_bookOfSpells[i]->clone());
	}
	std::cout << "Unknown spell : " << type << std::endl;
	return (0);
}

void MateriaSource::showBook() const
{
	std::cout << "Spell learned: "<< std::endl;
	for (int i = 0; i < MAX_SPELL; i++)
	{
		if (_bookOfSpells[i])
			std::cout << _bookOfSpells[i]->getType() << std::endl;
	}
}
