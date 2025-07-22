/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:36 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 17:51:55 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <math.h>

// Constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequest", _executionGrade, _signedGrade) , _target("Unknown")
{
	std::cout << "\e[2mDefault constructor RobotomyRequestForm called\e[0m" << std::endl;
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequest", _executionGrade, _signedGrade), _target(target)
{
	std::cout << "\e[2mParameterized constructor RobotomyRequestForm called\e[0m" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm("RobotomyRequest", _executionGrade, _signedGrade), _target(other._target + "_copy")
{
	std::cout << "\e[2mCopy constructor RobotomyRequestForm called\e[0m" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[2mDestructor RobotomyRequestForm called\e[0m" << std::endl;
}

// Overloads
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "\e[2mAssignation operator RobotomyRequestForm called\e[0m" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other); // to copy the base class as well
	}
	return (*this);
}

// Member functions
void	RobotomyRequestForm::executeAction() const
{
	bool	isSuccess;
	srand(time(0)); // Seed random number generator
	
	isSuccess = (rand() % 2) == 1;
	std::cout << "\e[3m[Robotomy starts : bip bip boop...]" << std::endl;
	std::cout << "[Brrrrrrrah brrrrrrah brrrrrrah]" << std::endl;
	std::cout << "[Paw paw paw drrrrrrrr]"  RESET << std::endl;
	if (!isSuccess)
		std::cout << RED "The company is so sad to announce you that " << _target << " is dead. (rip)" RESET << std::endl;
	else
		std::cout << GREEN "The company is so happy to announce you that " << _target << " is alive. (yay)" RESET << std::endl;
}

// Getters
std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

// Setters
