/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:49 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:56:50 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

#include <iostream>

Cat::Cat() : Animal(), brain(new Brain()) {
	std::cout << "\e[2mDefault constructor Cat called\e[0m" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "\e[2mCopy constructor Cat called\e[0m" << std::endl;
	this->type = other.type;
}

Cat::~Cat() {
	std::cout << "\e[2mDestructor Cat called\e[0m" << std::endl;
	delete this->brain;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Assignation Cat operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		// deep copy
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

// comment this function to trigger the pure virtual function error
void Cat::makeSound() const {
	std::cout << "Meeeeeeeeow" << std::endl;
}

//set idea in brain
void Cat::setIdeaInBrain(const std::string &idea, int index) {
	this->brain->setIdea(idea, index);
}

std::string Cat::getIdeaInBrain(int index) const {
	return this->brain->getIdea(index);
}
