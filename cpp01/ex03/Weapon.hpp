#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon{
	private:
		std::string type;
	public:
		Weapon(std::string t);
		~Weapon();
		const std::string &getType();
		void setType(const std::string &t);
};

#endif
