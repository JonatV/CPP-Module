#include "Character.hpp"

#include <iostream>

Character::Character() : _name("DefaultUser"), _inventory() {
	std::cout << "\e[2mDefault constructor Character called\e[0m" << std::endl;
}

Character::Character(const std::string &name) : _name(name), _inventory() {
	std::cout << "\e[2mParameterized constructor Character called\e[0m" << std::endl;
}

Character::Character(const Character &other) {
	std::cout << "\e[2mCopy constructor Character called\e[0m" << std::endl;
}

Character::~Character() {
	std::cout << "\e[2mDestructor Character called\e[0m" << std::endl;
}

Character &Character::operator=(const Character &other){
	std::cout << "\e[2mAssignation Character operator called\e[0m" << std::endl;
	return (*this);
}

// methods

// getters

// setters
