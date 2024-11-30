#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
	private:
		// std::string type;
	public:
		Cat();
		Cat(const Cat &);
		~Cat();

		Cat &operator=(const Cat &);

		void makeSound() const;
};


#endif
