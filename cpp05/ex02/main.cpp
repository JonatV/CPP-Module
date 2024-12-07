#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>
#include <math.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	try {
		Bureaucrat a;  // Calls default constructor
		Bureaucrat b("Alice", 1);  // Calls parameterized constructor

		std::cout << a;
		std::cout << b;
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception: " << myException.what() << std::endl;
	}
	std::cout << std::endl << "------------------------------------------------\n" << std::endl;

	Bureaucrat c("Ventouse", 10);  // Calls parameterized constructor
	ShrubberyCreationForm shrubbery("home");
	std::cout << shrubbery;
	try
	{
		shrubbery.beSigned(c);
		shrubbery.execute(c);
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Form::GradeTooHighException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::GradeTooLowException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::NotExecutedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::FormNotSignedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------------------------\n" << std::endl;
	srand(time(0)); // Seed random number generator

	RobotomyRequestForm robot("Donald");
	std::cout << robot;
	try
	{
		// robot.beSigned(c);// todo error when not signed
		robot.execute(c);
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Form::GradeTooHighException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::GradeTooLowException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::FormNotSignedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::NotExecutedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------------------------\n" << std::endl;

	PresidentialPardonForm president("Tanguy");
	std::cout << president;
	std::cout << c;
	try
	{
		c.incrementGrade(7);
		std::cout << c;
		president.beSigned(c);
		president.execute(c);
		c.executeForm(president);
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Form::GradeTooHighException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::GradeTooLowException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::FormNotSignedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::NotExecutedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	}

	return 0;
}