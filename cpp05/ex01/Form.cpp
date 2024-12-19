/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:20 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:58:20 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

// Constructor
Form::Form()
	: _name("DefaultForm"), _executionGrade(150), _signedGrade(150), _isSigned(false)
{
	// std::cout << "\e[2mDefault constructor Form called\e[0m" << std::endl;
}

// Parameterized constructor
Form::Form(std::string const &name, int executionGrade, int signedGrade)
	: _name(name), _executionGrade(executionGrade), _signedGrade(signedGrade), _isSigned(false)
{
	// std::cout << "\e[2mParameterized constructor Form called\e[0m" << std::endl;
	if (executionGrade < _maxGrade || signedGrade < _maxGrade)
		throw Form::GradeTooHighException();
	if (executionGrade > _minGrade || signedGrade > _minGrade)
		throw Form::GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &other)
	: _name(other._name), _executionGrade(other._executionGrade), _signedGrade(other._signedGrade), _isSigned(other._isSigned)
{
	// std::cout << "\e[2mCopy constructor Form called\e[0m" << std::endl;
}

// Destructor
Form::~Form()
{
	// std::cout << "\e[2mDestructor Form called\e[0m" << std::endl;
}

// Overload =
Form &Form::operator=(const Form &other)
{
	std::cout << "\e[2mAssignation operator Form called\e[0m" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

// Overload <<
std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << "Form title \"" MAGENTA << form.getName() << RESET "\"";
	os << " | ";
	os << (form.getIsSigned() ? GREEN "signed" : RED "not signed") << RESET;
	os << " | ";
	os << "can sign: " CYAN << form.getSignedGrade() << RESET;
	os << " | ";
	os << "can exec: " CYAN << form.getExecGrade() << RESET;
	os << std::endl;
	return (os);
}

// Member functions
void	Form::beSigned(const Bureaucrat &employee)
{
	if (employee.getGrade() > this->_signedGrade)
	{
		std::cout << "[" << employee.getName() << "] couldn't sign ";
		std::cout << MAGENTA << this->getName() << RESET << " because: ";
		throw Form::GradeTooLowException();
	}
	else if (this->_isSigned)
	{
		std::cout << "[" << employee.getName() << "] couldn't sign ";
		std::cout << "\"" MAGENTA << this->getName() << RESET "\"" << " because: ";
		std::cout << YELLOW << "Form already signed" << RESET << std::endl;
	}
	else
	{
		std::cout << "[" << employee.getName() << "]" GREEN << " signed " << RESET;
		std::cout << "\"" MAGENTA << this->getName() << RESET "\"" << std::endl;
		this->_isSigned = true;
	}
}
void	Form::beExecuted(const Bureaucrat &employee)
{
	if (employee.getGrade() > this->_executionGrade)
	{
		std::cout << "[" << employee.getName() << "] couldn't execute ";
		std::cout << "\"" MAGENTA << this->getName() << RESET "\"" << " because: ";
		throw Form::GradeTooLowException();
	}
	else if (!this->_isSigned)
	{
		std::cout << "[" << employee.getName() << "] couldn't execute ";
		std::cout << MAGENTA << this->getName() << RESET << " because: ";
		std::cout << RED << "Form is not signed" << RESET << std::endl;
	}
	else
	{
		std::cout << "[" << employee.getName() << "]" GREEN << " executed " << RESET;
		std::cout << "\"" MAGENTA << this->getName() << RESET "\"" << std::endl;
	}
}

// Getters
std::string const &Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getSignedGrade() const
{
	return (this->_signedGrade);
}

int Form::getExecGrade() const
{
	return (this->_executionGrade);
}

// Setters
void	Form::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

// exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high for a Form" RESET;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low for a Form" RESET;
}
