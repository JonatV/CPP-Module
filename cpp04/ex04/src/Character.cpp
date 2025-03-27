/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:01:20 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/27 03:04:36 by jveirman         ###   ########.fr       */
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

// https://www.w3schools.com/cpp/cpp_iterators.asp for better understand the iterators on list
Character::~Character()
{
	std::cout << "\e[2mDestructor Character called\e[0m" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for (std::list<AMateria*>::iterator it = _unequipped.begin(); it != _unequipped.end(); it++)
		delete *it;
}

// todo - check if the it works correctly for the subject
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
		if (this->_inventory[i] == mat)
		{
			std::cout << mat->getType() << " already equipped" << std::endl;
			return ;
		}
		if (!this->_inventory[i])
		{
			this->_inventory[i] = mat;
			std::cout << "Equipped " << mat->getType() << std::endl;
			std::cout << "Space left: " << MAX_MATERIA - i - 1 << std::endl;
			return ;
		}
	}
	std::cout << "Inventory full, can't equip " << mat->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Invalid index number" << std::endl;
	else if (!_inventory[idx])
		std::cout << "Slot empty, can't unequip" << std::endl;
	else
	{
		this->_unequipped.push_back(_inventory[idx]);
		_inventory[idx] = NULL;
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
