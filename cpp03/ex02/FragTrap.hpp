#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		bool _isHighFivesGuys;
	public:
		FragTrap();
		FragTrap(std::string);
		FragTrap(const FragTrap &);

		~FragTrap();

		FragTrap &operator=(const FragTrap &);
		void highFivesGuys();
};


#endif
