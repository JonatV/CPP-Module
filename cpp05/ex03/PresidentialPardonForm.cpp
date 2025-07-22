/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:15 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 18:25:32 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

// Constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardon", _executionGrade, _signedGrade) , _target("Unknown")
{
	std::cout << "\e[2mDefault constructor PresidentialPardonForm called\e[0m" << std::endl;
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardon", _executionGrade, _signedGrade), _target(target)
{
	std::cout << "\e[2mParameterized constructor PresidentialPardonForm called\e[0m" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm("PresidentialPardon", _executionGrade, _signedGrade), _target(other._target + "_copy")
{
	std::cout << "\e[2mCopy constructor PresidentialPardonForm called\e[0m" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[2mDestructor PresidentialPardonForm called\e[0m" << std::endl;
}

// Overloads
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "\e[2mAssignation operator PresidentialPardonForm called\e[0m" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other); // to copy the base class as well
	}
	return (*this);
}

// Member functions
void	PresidentialPardonForm::executeAction() const
{
	std::cout << GREEN "Lucky day! " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" RESET << std::endl;
}

// Getters
std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

// Setters
