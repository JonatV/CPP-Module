/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:20:09 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 13:28:53 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "\e[2mDefault constructor Cure called\e[0m" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "\e[2mCopy constructor Cure called\e[0m" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "\e[2mAssignation Cure operator called\e[0m" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "\e[2mDestructor Cure called\e[0m" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
