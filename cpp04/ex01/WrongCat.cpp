#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "\e[2mDefault constructor WrongCat called\e[0m" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "\e[2mCopy constructor WrongCat called\e[0m" << std::endl;
	*this = other;
}

WrongCat::~WrongCat() {
	std::cout << "\e[2mDestructor WrongCat called\e[0m" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	std::cout << "Assignation WrongCat operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meeeeeeeeow (wrong cat)" << std::endl;
}