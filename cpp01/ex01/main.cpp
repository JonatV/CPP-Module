#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int n, std::string name);

int	main()
{
	int n = 10;
	Zombie zombieStack("StackBrainEater");
	
	zombieStack.announce();
	std::cout << std::endl;
	Zombie *gang = zombieHorde(n, "LeakingSquad");
	for (int i = 0; i < n; i++)
		gang[i].announce();
	std::cout << std::endl;
	delete[] gang;
	return 0;
}
