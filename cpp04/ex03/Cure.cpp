/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:57:08 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:57:08 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("ice") {
	std::cout << "\e[2mDefault constructor Cure called\e[0m" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	std::cout << "\e[2mCopy constructor Cure called\e[0m" << std::endl;
}

Cure::~Cure() {
	std::cout << "\e[2mDestructor Cure called\e[0m" << std::endl;
}

Cure &Cure::operator=(const Cure &other){
	std::cout << "\e[2mAssignation Cure operator called\e[0m" << std::endl;
	return (*this);
}

// methods
AMateria *Cure::clone() const {
	return (new Cure(*this));
}

// getters
void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
