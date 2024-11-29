#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string);
		DiamondTrap(const DiamondTrap &);

		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &);

		void attack(const std::string &);
		void whoAmI();
		void displayName();
};

#endif
