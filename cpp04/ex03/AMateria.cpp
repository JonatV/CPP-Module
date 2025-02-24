/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:57:03 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:57:03 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>


AMateria::AMateria() : _type("Unknown") {
	std::cout << "\e[2mDefault constructor AMateria called\e[0m" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	std::cout << "\e[2mParameterized constructor AMateria called\e[0m" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
	std::cout << "\e[2mCopy constructor AMateria called\e[0m" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "\e[2mDestructor AMateria called\e[0m" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other){
	std::cout << "\e[2mAssignation AMateria operator called\e[0m" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

// methods
void AMateria::use(ICharacter &target){
	std::cout << "use function called." << std::endl;
}

// getters
std::string const &AMateria::getType () const {
	return (this->_type);
}


