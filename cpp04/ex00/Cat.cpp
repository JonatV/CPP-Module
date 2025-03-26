/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:55:23 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 09:33:39 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal() {
	std::cout << "\e[2mDefault constructor Cat called\e[0m" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "\e[2mCopy constructor Cat called\e[0m" << std::endl;
	this->type = other.type;
}

Cat::~Cat() {
	std::cout << "\e[2mDestructor Cat called\e[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Assignation Cat operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meeeeeeeeow" << std::endl;
}
