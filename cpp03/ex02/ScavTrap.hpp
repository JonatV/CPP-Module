#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool _isGuard;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &);
		ScavTrap(std::string);

		~ScavTrap();
		
		ScavTrap &operator=(const ScavTrap &);

		void attack(const std::string &);
		void guardGate();
};

#endif
