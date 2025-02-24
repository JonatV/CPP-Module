/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:54:36 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:54:36 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap21_clap_trap"), ScavTrap("DiamondTrap21"), FragTrap("DiamondTrap21")
{
	std::cout << "\e[2mDefault constructor DiamondTrap called\e[0m" << std::endl;
	this->_name = "DiamondTrap21";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_hitPointsMax = FragTrap::_hitPointsMax;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
	std::cout << "\e[2mParametrized constructor DiamondTrap called\e[0m" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_hitPointsMax = FragTrap::_hitPointsMax;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "Copy constructor DiamondTrap called" << std::endl;
	this->_name = other._name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[2mDestructor DiamondTrap called\e[0m" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Assignation DiamondTrap operator called" << std::endl;
	this->_name = other._name + "_clap_trap";
	this->_hitPoints = other._hitPoints;
	this->_hitPointsMax = other._hitPointsMax;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

// void DiamondTrap::attack(const std::string &target)
// {	
// 	displayName();
// 	// ClapTrap::displayName();
// 	if (this->_hitPoints == 0)
// 		std::cout << "\e[31mAttack denied. Crew is dead, no one can attack.\e[0m " << std::endl;
// 	else if (this->_energyPoints > 0)
// 	{
// 		std::cout << "\e[32mDeal \e[42m" << _attackDamage << "\e[0;32m of damage to \e[0m[" << target << "]\e[0;32m.\e[0m" << std::endl;
// 		this->_energyPoints--;
// 	}
// 	else
// 		std::cout << "\e[33mAttack denied. Not enought energy.\e[0m " << std::endl;
// }

void DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}


void DiamondTrap::displayName(){
	if (this->_hitPoints == 0)
		std::cout << "[ \e[9m"<< this->_name << "\e[0m DEAD]\t";
	else
		std::cout << "["<< this->_name << " " << this->getHp() << "/" << this->getHpMax() << "]\t";
}
