/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:07 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 18:23:34 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

// Constructor
AForm::AForm()
	: _name("DefaultForm"), _executionGrade(150), _signedGrade(150), _isSigned(false)
{
	std::cout << "\e[2mDefault constructor Form called\e[0m" << std::endl;
}

// Parameterized constructor
AForm::AForm(std::string const &name, int executionGrade, int signedGrade)
	: _name(name), _executionGrade(executionGrade), _signedGrade(signedGrade), _isSigned(false)
{
	std::cout << "\e[2mParameterized constructor Form called\e[0m" << std::endl;
	if (executionGrade < _maxGrade || signedGrade < _maxGrade)
		throw AForm::GradeTooHighException();
	if (executionGrade > _minGrade || signedGrade > _minGrade)
		throw AForm::GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other)
	: _name(other._name), _executionGrade(other._executionGrade), _signedGrade(other._signedGrade), _isSigned(other._isSigned)
{
	std::cout << "\e[2mCopy constructor Form called\e[0m" << std::endl;
}

// Destructor
AForm::~AForm()
{
	std::cout << "\e[2mDestructor Form called\e[0m" << std::endl;
}

// Overload =
AForm &AForm::operator=(const AForm &other)
{
	std::cout << "\e[2mAssignation operator Form called\e[0m" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

// Overload <<
std::ostream	&operator<<(std::ostream &os, const AForm &form)
{
	os << "\"" MAGENTA << form.getName() << RESET "\"";
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
void	AForm::beSigned(const Bureaucrat &employee)
{
	if (employee.getGrade() > this->_signedGrade)
	{
		std::cout << "[" << employee.getName() << "] couldn't sign ";
		std::cout << MAGENTA << this->getName() << RESET << " because: ";
		throw AForm::GradeTooLowException();
	}
	else if (this->_isSigned)
	{
		std::cout << "[" << employee.getName() << "] couldn't sign ";
		std::cout << "\"" MAGENTA << this->getName() << RESET "\"" << " because: ";
		std::cout << YELLOW << "Form's already signed" << RESET << std::endl;
	}
	else
	{
		std::cout << "[" << employee.getName() << "]" GREEN << " signed " << RESET;
		std::cout << "\"" MAGENTA << this->getName() << RESET "\"" << std::endl;
		this->_isSigned = true;
	}
}
void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->_executionGrade)
	{
		std::cout << "[" << executor.getName() << "] couldn't execute ";
		std::cout << "\"" MAGENTA << this->getName() << RESET "\"" << " because: ";
		throw AForm::GradeTooLowException();
	}
	else if (!this->_isSigned)
	{
		std::cout << "[" << executor.getName() << "] couldn't execute ";
		std::cout << MAGENTA << this->getName() << RESET << " because: ";
		throw AForm::FormNotSignedException();
	}
	else
	{
		executeAction();
		std::cout << "[" << executor.getName() << "]" GREEN << " executed " << RESET;
		std::cout << "\"" MAGENTA << this->getName() << RESET "\"" << std::endl;
	}
}

// Getters
std::string const &AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getSignedGrade() const
{
	return (this->_signedGrade);
}

int AForm::getExecGrade() const
{
	return (this->_executionGrade);
}

// Setters
void	AForm::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

// exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high" RESET;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low" RESET;
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return RED "Form is not signed" RESET;
}

const char *AForm::NotExecutedException::what() const throw()
{
	return YELLOW "No execution, a similar name of file already exists" RESET;
}

const char *AForm::FormTypeUnknownException::what() const throw()
{
	return RED "This type of form doesn't exists" RESET;
}
