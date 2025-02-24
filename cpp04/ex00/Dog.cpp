/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:55:21 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:55:21 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "\e[2mDefault constructor Dog called\e[0m" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "\e[2mCopy constructor Dog called\e[0m" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << "\e[2mDestructor Dog called\e[0m" << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Assignation Dog operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof woof I'm a dog" << std::endl;
}
