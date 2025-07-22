/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:18 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 18:29:12 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

// Constructor
Intern::Intern()
{
	std::cout << "\e[2mDefault constructor Intern called\e[0m" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern &)
{
	std::cout << "\e[2mCopy constructor Intern called\e[0m" << std::endl;
}

// Destructor
Intern::~Intern()
{
	std::cout << "\e[2mDestructor Intern called\e[0m" << std::endl;
}

// Overloads
Intern	&Intern::operator=(const Intern &)
{
	std::cout << "\e[2mAssignation operator Intern called\e[0m" << std::endl;
	return (*this);
}

// Member functions

AForm *Intern::makeForm(std::string form_type, std::string target)
{
	std::string	all_forms[4] = {"shrubbery creation", "robotomy request", "presidential pardon", ""};
	int	i;

	i = 0;
	while (!(all_forms[i].empty()) && all_forms[i] != form_type)
		i++;
	switch (i)
	{
		case 0:
			std::cout << "[Intern] creates " << all_forms[i] << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "[Intern] creates " << all_forms[i] << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "[Intern] creates " << all_forms[i] << std::endl;
			return (new PresidentialPardonForm(target)); 
		default:
			throw AForm::FormTypeUnknownException();
	}
}
// Getters

// Setters
