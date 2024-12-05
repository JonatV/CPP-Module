#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	try {
		Bureaucrat a;  // Calls default constructor
		Bureaucrat b("Alice", 1);  // Calls parameterized constructor

		std::cout << a << std::endl;
		std::cout << b << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception: " << myException.what() << std::endl;
	}

	try {
		Bureaucrat c("Ventouse", 150);  // Calls parameterized constructor
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
		c.decrementGrade();
		std::cout << c << std::endl;
		c.decrementGrade(); // here we go under the minimum grade must throw an exception
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception: " << myException.what() << std::endl;
	}
	return 0;
}
