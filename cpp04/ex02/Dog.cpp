/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:47 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:56:48 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal(), brain(new Brain()) {
	std::cout << "\e[2mDefault constructor Dog called\e[0m" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "\e[2mCopy constructor Dog called\e[0m" << std::endl;
	this->type = other.type;
}

Dog::~Dog() {
	std::cout << "\e[2mDestructor Dog called\e[0m" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Assignation Dog operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof woof I'm a dog" << std::endl;
}

//set idea in brain
void Dog::setIdeaInBrain(const std::string &idea, int index) {
	this->brain->setIdea(idea, index);
}

std::string Dog::getIdeaInBrain(int index) const {
	return this->brain->getIdea(index);
}
