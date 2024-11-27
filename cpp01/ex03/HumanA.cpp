#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string n, Weapon &w) : name(n), weapon(w){};
HumanA::~HumanA(){};
void HumanA::attack(){
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
