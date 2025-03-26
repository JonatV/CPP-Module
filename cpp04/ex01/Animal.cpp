/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:12 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 09:55:17 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal") {
	std::cout << "\e[2mDefault constructor Animal called\e[0m" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "\e[2mCopy constructor Animal called\e[0m" << std::endl;
}

Animal::~Animal() {
	std::cout << "\e[2mDestructor Animal called\e[0m" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "Assignation Animal operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Unknown sound" << std::endl;
}

std::string Animal::getType() const{
	return (this->type);
}
