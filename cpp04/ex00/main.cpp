#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << std::endl;
	
	meta->makeSound();
	wrong_meta->makeSound();
	wrong_cat->makeSound();
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;

	delete meta;
	delete wrong_meta;
	delete wrong_cat;
	delete i;
	delete j;
	return (0);
}
