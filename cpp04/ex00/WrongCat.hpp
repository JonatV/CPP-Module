#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
	private:
		// std::string type;
	public:
		WrongCat();
		WrongCat(const WrongCat &);
		~WrongCat();

		WrongCat &operator=(const WrongCat &);

		void makeSound() const;
};


#endif
