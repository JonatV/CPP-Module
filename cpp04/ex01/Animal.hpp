#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &);
		virtual ~Animal();

		Animal &operator=(const Animal &);

		virtual void makeSound() const;

		// getters
		std::string getType() const;
};


#endif
