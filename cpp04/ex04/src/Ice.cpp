/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:20:09 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/27 03:52:47 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "\e[2mDefault constructor Ice called\e[0m" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "\e[2mCopy constructor Ice called\e[0m" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "\e[2mAssignation Ice operator called\e[0m" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "\e[2mDestructor Ice called\e[0m" << std::endl;
}

AMateria* Ice::clone() const
{
	Ice *clone = new Ice;
	return (clone);
}

void Ice::use(ICharacter &target)
{
	std::cout << "\e[34m* shoots an ice bolt at " << target.getName() << " *\e[0m" << std::endl;
}
