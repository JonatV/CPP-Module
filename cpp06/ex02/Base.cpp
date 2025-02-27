#include "Base.hpp"

#include <iostream>

// Constructor
Base::Base()
{
	std::cout << "\e[2mDefault constructor Base called\e[0m" << std::endl;
}

// Parameterized constructor
// Base::Base()
// {
// 	std::cout << "\e[2mParameterized constructor Base called\e[0m" << std::endl;
// }

// Copy constructor
Base::Base(const Base &other)
{
	std::cout << "\e[2mCopy constructor Base called\e[0m" << std::endl;
}

// Destructor
Base::~Base()
{
	std::cout << "\e[2mDestructor Base called\e[0m" << std::endl;
}

// Overloads
Base	&Base::operator=(const Base &other)
{
	std::cout << "\e[2mAssignation operator Base called\e[0m" << std::endl;
	return (*this);
}

// Member functions

// Getters

// Setters
