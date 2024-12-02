#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {
	std::cout << "\e[2mDefault constructor Ice called\e[0m" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	std::cout << "\e[2mCopy constructor Ice called\e[0m" << std::endl;
}

Ice::~Ice() {
	std::cout << "\e[2mDestructor Ice called\e[0m" << std::endl;
}

Ice &Ice::operator=(const Ice &other){
	std::cout << "\e[2mAssignation Ice operator called\e[0m" << std::endl;
	return (*this);
}

// methods
AMateria *Ice::clone() const {
	return (new Ice(*this));
}

// getters
void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
