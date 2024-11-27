#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string n);
		~Zombie();
		void setName(std::string n);
		void announce(void);
};
#endif
