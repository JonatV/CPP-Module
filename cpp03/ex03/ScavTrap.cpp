/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:54:27 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:54:30 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("ScavTrap4242")
{
	std::cout << "\e[2mDefault constructor ScavTrap called\e[0m" << std::endl;
	this->_hitPoints = 100;
	this->_hitPointsMax = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGuard = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\e[2mParametrized constructor ScavTrap called\e[0m" << std::endl;
	this->_hitPoints = 100;
	this->_hitPointsMax = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGuard = false;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor ScavTrap called" << std::endl;
	this->_isGuard = other._isGuard;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\e[2mDestructor ScavTrap called\e[0m" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Assignation ScavTrap operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_hitPointsMax = other._hitPointsMax;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	displayName();
	if (this->_hitPoints == 0)
		std::cout << "\e[31mAttack denied. Crew is dead, no one can attack.\e[0m " << std::endl;
	else if (this->_energyPoints > 0)
	{
		std::cout << "\e[32mDeal \e[42m" << _attackDamage << "\e[0;32m of damage to \e[0m[" << target << "]\e[0;32m.\e[0m" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "\e[33mAttack denied. Not enought energy.\e[0m " << std::endl;
}

void ScavTrap::guardGate()
{
	displayName();
	this->_isGuard = !this->_isGuard;
	if (this->_isGuard)
		std::cout << "\e[32mEnabled Gate keeper mode.\e[0m" << std::endl;
	else
		std::cout << "\e[33mDisabled Gate keeper mode.\e[0m" << std::endl;
}
