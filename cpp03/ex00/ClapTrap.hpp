#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _hitPointsMax;
		int _energyPoints;
		int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &src);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		const std::string& getName();
		const int& getHp();
		const int& getHpMax();
		void displayHP();
		void displayDMG();
		void displayEnergy();
		void displayName();

};

#endif
