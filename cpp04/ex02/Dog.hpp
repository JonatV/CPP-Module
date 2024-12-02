#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &);
		~Dog();

		Dog &operator=(const Dog &);

		void makeSound() const;
		//set idea in brain
		void setIdeaInBrain(const std::string &idea, int index);
		std::string getIdeaInBrain(int index) const;
};


#endif