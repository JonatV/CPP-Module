#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &);

		void makeSound() const;

		// getters
		std::string getType() const;
};


#endif
