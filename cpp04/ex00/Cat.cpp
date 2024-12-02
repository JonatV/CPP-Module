#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal() {
	std::cout << "\e[2mDefault constructor Cat called\e[0m" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "\e[2mCopy constructor Cat called\e[0m" << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << "\e[2mDestructor Cat called\e[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Assignation Cat operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meeeeeeeeow" << std::endl;
}