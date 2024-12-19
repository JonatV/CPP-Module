/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:18 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:58:18 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>

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

	try {
		Bureaucrat c("Ventouse", 150);  // Calls parameterized constructor
		std::cout << c;
		c.incrementGrade();
		std::cout << c;
		c.decrementGrade();
		std::cout << c;
		c.incrementGrade(140);
		std::cout << c;
		// c.decrementGrade(); // uncomment to have an error while signing (expect "grade is too low" error)
		Form form1("Destroy the company?", 10, 10);
		std::cout << "Form title: "<< form1.getName() << std::endl;
		std::cout << (form1.getIsSigned() ? "The doc is" GREEN " signed" RESET : "The doc is " RED "NOT signed" RESET) << std::endl;
		std::cout << "To signed this doc, employee must be at least grade: " CYAN << form1.getSignedGrade() << RESET << std::endl;
		std::cout << c;
		std::cout << form1;
		form1.beSigned(c);
		form1.beSigned(c);
		form1.beExecuted(c);
		std::cout << form1;
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Form::GradeTooHighException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const Form::GradeTooLowException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	}

	return 0;
}
