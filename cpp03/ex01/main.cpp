#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap tankUS("\e[34mEagleBrrrTank\e[0m");
	ClapTrap tankGER("\e[35mFuhrerTankzer\e[0m");
	ScavTrap scavUS("\e[36mLibertyScav\e[0m");

	std::cout << std::endl;
	tankUS.attack(tankGER.getName());
	tankGER.takeDamage(1);
	tankGER.attack(tankUS.getName());
	tankUS.takeDamage(2);

	tankUS.attack(tankGER.getName());
	tankGER.takeDamage(1);
	tankGER.takeDamage(1);
	tankGER.takeDamage(1);
	tankGER.takeDamage(4);
	tankGER.attack(tankUS.getName());
	tankUS.takeDamage(2);
	tankUS.takeDamage(2);
	tankUS.takeDamage(2);

	tankUS.beRepaired(2);
	tankGER.attack(tankUS.getName());
	tankUS.takeDamage(2);
	tankUS.attack(tankGER.getName());
	tankGER.takeDamage(1);
	tankGER.beRepaired(1000);
	tankGER.attack(tankUS.getName());
	tankUS.takeDamage(666);
	tankGER.attack(tankGER.getName());
	tankUS.takeDamage(1);
	tankUS.attack(tankGER.getName());
	tankUS.beRepaired(42);
	scavUS.attack(tankGER.getName());
	tankGER.takeDamage(20);
	scavUS.guardGate();
	scavUS.guardGate();
	scavUS.takeDamage(20);
	scavUS.beRepaired(20);
	std::cout << scavUS.getName() << " WINS!" << std::endl;
	std::cout << std::endl;
	return (0);
}
