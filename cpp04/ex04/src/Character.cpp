/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:01:20 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 18:20:04 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character() : _name("Guest19")
{
	std::cout << "\e[2mDefault constructor Character called\e[0m" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "\e[2mParameterized constructor Character called\e[0m" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	std::cout << "\e[2mCopy constructor Character called\e[0m" << std::endl;
	*this = other;
}

Character::~Character()
{
	std::cout << "\e[2mDestructor Character called\e[0m" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	for (std::list<AMateria*>::iterator it = _unequipped.begin(); it != _unequipped.end(); it++)
	{
		delete *it;
	}
}

Character &Character::operator=(const Character &other)
{
	std::cout << "\e[2mAssignation operator Character called\e[0m" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = other._inventory[i]->clone();
	}
	for (std::list<AMateria*>::iterator it = _unequipped.begin(); it != _unequipped.end(); it++)
	{
		delete *it;
	}
	_unequipped.clear();
	for (std::list<AMateria*>::const_iterator it = other._unequipped.begin(); it != other._unequipped.end(); it++)
	{
		_unequipped.push_back((*it)->clone());
	}
	return (*this);
}

const std::string &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *mat)
{
	if (!mat)
		return ;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = mat;
			return ;
		}
	}
void Character::showInventory() const
{
	std::cout << "Inventory of " << getName() << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i])
			std::cout << _inventory[i]->getType() << std::endl;
	}
}
