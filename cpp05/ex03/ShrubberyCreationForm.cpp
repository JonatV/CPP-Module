/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:11 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 18:28:04 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>
#include <unistd.h>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreation", _executionGrade, _signedGrade) , _target("Unknown")
{
	std::cout << "\e[2mDefault constructor ShrubberyCreationForm called\e[0m" << std::endl;
}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreation", _executionGrade, _signedGrade), _target(target)
{
	std::cout << "\e[2mParameterized constructor ShrubberyCreationForm called\e[0m" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm("ShrubberyCreation", _executionGrade, _signedGrade), _target(other._target + "_copy")
{
	std::cout << "\e[2mCopy constructor ShrubberyCreationForm called\e[0m" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[2mDestructor ShrubberyCreationForm called\e[0m" << std::endl;
}

// Overloads
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "\e[2mAssignation operator ShrubberyCreationForm called\e[0m" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other); // to copy the base class as well
	}
	return (*this);
}

// Member functions
void	ShrubberyCreationForm::executeAction() const
{
	std::string	answer;
	std::string	modified_file_name = _target + "_shrubbery";
	if (checkIfFileExists(modified_file_name))
	{
		while (answer != "y" && answer != "n")
		{
				std::cout << YELLOW "Conflict" RESET << " : File already exists, do you want to overwrite it? (y/n) :"; 
				std::getline(std::cin, answer);
		}
		if (answer == "n")
			throw AForm::NotExecutedException();
	}
	std::ofstream f(modified_file_name.c_str());
	if (f.is_open())
	{
		f <<
		"              * *    " << std::endl <<
		"           *    *  *" << std::endl <<
		"      *  *    *     *  *" << std::endl <<
		"     *     *    *  *    *" << std::endl <<
		" * *   *    *    *    *   *" << std::endl <<
		" *     *  *    * * .#  *   *" << std::endl <<
		" *   *     * #.  .# *   *" << std::endl <<
		"  *     \"#.  #: #\" * *    *" << std::endl <<
		" *   * * \"#. ##\"       *" << std::endl <<
		"   *       \"###" << std::endl <<
		"             \"##" << std::endl <<
		"              ##." << std::endl <<
		"              .##:" << std::endl <<
		"              :###" << std::endl <<
		"              ;###" << std::endl <<
		"            ,####." << std::endl <<
		"__\\/__\\/___.######.__\\___\\\\/____" << std::endl;
		f.close();
	}
	else
	{
		std::cerr << RED "Error: " << modified_file_name << " while opening file" << std::endl;
	}
}

bool	ShrubberyCreationForm::checkIfFileExists(std::string &file_name) const {
	return ( access( file_name.c_str(), F_OK ) != -1 );
}

// Getters
std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}
