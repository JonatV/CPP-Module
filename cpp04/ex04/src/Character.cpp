/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:01:20 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 14:08:40 by jveirman         ###   ########.fr       */
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
}

const std::string &Character::getName() const
{
	return (this->_name);
}
