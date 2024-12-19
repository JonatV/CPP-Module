/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:55:58 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:55:59 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int	main(void)
{

	const Animal *zoo[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

	for (int i = 0; i < 4; i++)
	{
		zoo[i]->makeSound();
		delete zoo[i];
	}
	std::cout << std::endl;

	Dog *dog = new Dog();

	std::cout << std::endl;
	dog->setIdeaInBrain("I'm a dog", 0);
	dog->setIdeaInBrain("I'm a big dog", 1);
	dog->setIdeaInBrain("I'm a small dog", 2);
	for (int i = 0; i < 3; i++)
		std::cout << "Idea " << i << ": " << dog->getIdeaInBrain(i) << std::endl;
	std::cout << std::endl;
	delete dog;
	Cat *cat = new Cat();

	std::cout << std::endl;
	cat->setIdeaInBrain("Chasing a mouse", 0);
	cat->setIdeaInBrain("Blackmailing my owner for food", 1);
	cat->setIdeaInBrain("Sleeping as high as possible", 2);
	for (int i = 0; i < 3; i++)
		std::cout << "Idea " << i << ": " << cat->getIdeaInBrain(i) << std::endl;
	std::cout << std::endl;
	delete cat;
	// test by https://github.com/tblaase
	//THIS PART IS FOR TESTING DEEP COPY ↓

	std::cout << std::endl << std::endl;
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Dog *a = new Dog();
	// Cat *a = new Cat();
	if (a == NULL)
	{
		std::cerr << "Exiting the process now." << std::endl;
		return (1);
	}

	a->setIdeaInBrain("I have to sniff it", 0);
	a->setIdeaInBrain("I have to pee on it", 1);
	a->setIdeaInBrain("I have to sniff it again", 2);

	Dog *b = new Dog(*a);
	// Cat *b = new Cat(*a);
	if (b == NULL)
	{
		std::cerr << "Exiting the process now." << std::endl;
		return (1);
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting a\033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	for(int i = 0; i < 3; i++)
		std::cout << a->getIdeaInBrain(i) << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b\033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	for(int i = 0; i < 3; i++)
		std::cout << b->getIdeaInBrain(i) << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
	delete(b);
	return (0);
}
