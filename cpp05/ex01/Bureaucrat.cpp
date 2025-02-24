/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:16 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:58:16 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

// Constructor
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	// std::cout << "\e[2mDefault constructor Bureaucrat called\e[0m" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	// std::cout << "\e[2mParameterized constructor Bureaucrat called\e[0m" << std::endl;

	if (grade < _maxGrade) // if 0 < 1 we are above the system
		throw Bureaucrat::GradeTooHighException();
	else if (grade > _minGrade) // if 666 > 150 we are too low
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	// std::cout << "\e[2mCopy constructor Bureaucrat called\e[0m" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	// std::cout << "\e[2mDestructor Bureaucrat called\e[0m" << std::endl;
}

// Overloads
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "\e[2mAssignation operator Bureaucrat called\e[0m" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

// Member functions
void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < _maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::incrementGrade(int gainedGrade)
{
	if (_grade - gainedGrade < _maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade -= gainedGrade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > _minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::decrementGrade(int reducedGrade)
{
	if (_grade + reducedGrade > _minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += reducedGrade;
}
// Getters
const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// Setters

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

// overload <<
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << "[" << bureaucrat._name << "], bureaucrat grade " CYAN << bureaucrat._grade << RESET;
	os << std::endl;
	return (os);
}

// exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high for a Bureaucrat" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low for a Bureaucrat" RESET;
}
