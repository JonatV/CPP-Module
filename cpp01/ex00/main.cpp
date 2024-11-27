#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int	main()
{
	Zombie zombieStack("StackBrainEater");
	Zombie *zombieHeap = newZombie("RottenHeapCrawler");
	
	zombieStack.announce();
	zombieHeap->announce();
	std::cout << std::endl;
	randomChump("NoBrainNoGain");
	std::cout << std::endl;
	delete zombieHeap;
	std::cout << std::endl;
	return 0;
}
