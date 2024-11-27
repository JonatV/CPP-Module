#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string n) : name(n) {};
HumanB::~HumanB(){};

void	HumanB::attack(){
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their " << "very dangerous hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &w){
	weapon = &w;
}
