#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}
Zombie::Zombie(std::string n) : name(n) {}
Zombie::~Zombie() {
	std::cout << name << " is now more dead than usual" << std::endl;
}

void Zombie::setName(std::string n)
{
	name = n;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
