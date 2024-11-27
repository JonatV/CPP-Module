#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
	if (n <= 0)
		return (NULL);
	Zombie *zombieHorde = new Zombie[n];
	for (int i = 0; i < n; i++)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}
