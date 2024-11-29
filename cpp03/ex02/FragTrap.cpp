#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("FragTrap1337")
{
	std::cout << "\e[2mDefault constructor FragTrap called\e[0m" << std::endl;
	this->_hitPoints = 100;
	this->_hitPointsMax = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_isHighFivesGuys = false;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\e[2mParametrized constructor FragTrap called\e[0m" << std::endl;
	this->_hitPoints = 100;
	this->_hitPointsMax = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_isHighFivesGuys = false;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor FragTrap called" << std::endl;
	this->_isHighFivesGuys = other._isHighFivesGuys;
}

FragTrap::~FragTrap()
{
	std::cout << "\e[2mDestructor FragTrap called\e[0m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Assignation FragTrap operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_hitPointsMax = other._hitPointsMax;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

void FragTrap::highFivesGuys()
{
	displayName();
	this->_isHighFivesGuys = !this->_isHighFivesGuys;
	if (this->_isHighFivesGuys)
		std::cout << "\e[32m Enable damage, firerate and health regen bonuses!\e[0m" << std::endl;
	else
		std::cout << "\e[33m Disable damage, firerate and health regen bonuses!\e[0m" << std::endl;
}
