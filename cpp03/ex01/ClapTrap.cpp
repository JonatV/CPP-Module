/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:53:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/24 15:00:29 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("ClapTrap1919"), _hitPoints(10), _hitPointsMax(10), _energyPoints(10), _attackDamage(0){
	std::cout << "\e[2mDefault constructor called\e[0m" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _hitPointsMax(10), _energyPoints(10), _attackDamage(0){
	std::cout << "\e[2mParametrized constructor called\e[0m" << std::endl;
}
ClapTrap::~ClapTrap(){
	std::cout << "\e[2mDestructor called\e[0m" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_hitPointsMax = other._hitPointsMax;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string &target){
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

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints == 0)
	{
		displayName();
		std::cout << "\e[31mTaking damage denied. Dead can't be more dead.\e[0m " << std::endl;
	}
	else
	{
		if (this->_hitPoints - (int)amount <= 0)
		{
			this->_hitPoints = 0;
			displayName();
			std::cout << "\e[41mKILLED\e[0m ";
		}
		else
		{
			this->_hitPoints -= amount;
			displayName();
		}
		std::cout << "\e[31mTake \e[41m" << amount << "\e[0;31m of damage.\e[0m" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints == 0)
	{
		displayName();
		std::cout << "\e[31mRepair denied. It's too late, you can only bring flowers to their grave\e[0m " << std::endl;
	}
	else if (this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		if (this->_hitPointsMax < this->_hitPoints)
			this->_hitPoints = this->_hitPointsMax;
		this->_energyPoints--;
		displayName();
		std::cout << "\e[32mRepair \e[42m" << amount << "\e[0;32m.\e[0m" << std::endl;
	}
	else 
		std::cout << "\e[33mRepair denied. Not enought energy.\e[0m " << std::endl;
}

void ClapTrap::displayHP(){
	std::cout << "(" << this->_hitPoints << "/" << this->_hitPointsMax << " HP)" << std::endl;
}

void ClapTrap::displayDMG(){
	std::cout << "(" << this->_attackDamage << " DMG)" << std::endl;
}

void ClapTrap::displayEnergy(){
	std::cout << "(" << this->_energyPoints << " ENERGY)" << std::endl;
}

void ClapTrap::displayName(){
	if (this->_hitPoints == 0)
		std::cout << "[\e[9m"<< this->_name << "\e[0m DEAD]\t";
	else
		std::cout << "["<< this->_name << " " << this->getHp() << "/" << this->getHpMax() << "]\t";
}

const std::string& ClapTrap::getName() {
	return (this->_name);
}

const int& ClapTrap::getHp() {
	return (this->_hitPoints);
}

const int& ClapTrap::getHpMax() {
	return (this->_hitPointsMax);
}
