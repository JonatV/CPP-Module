/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:11:09 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 14:04:29 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria() : _type("unknown")
{
	std::cout << "\e[2mDefault constructor AMateria called\e[0m" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "\e[2mParameterized constructor AMateria called\e[0m" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	(void)other;
	std::cout << "\e[2mCopy constructor AMateria called\e[0m" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "\e[2mAssignation AMateria operator called\e[0m" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "\e[2mDestructor AMateria called\e[0m" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Default use on " << target.getName() << std::endl;
}
