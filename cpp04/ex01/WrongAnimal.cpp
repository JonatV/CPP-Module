/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:16 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 09:56:09 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : type("UnknownWrong") {
	std::cout << "\e[2mDefault constructor WrongAnimal called\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "\e[2mCopy constructor WrongAnimal called\e[0m" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "\e[2mDestructor WrongAnimal called\e[0m" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	std::cout << "Assignation WrongAnimal operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const{
	return (this->type);
}
