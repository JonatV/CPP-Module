#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
	private:
		// std::string type;
	public:
		Dog();
		Dog(const Dog &);
		~Dog();

		Dog &operator=(const Dog &);

		void makeSound() const;
};


#endif
