#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name)
{
	Zombie zombz(name);
	zombz.announce();
}
