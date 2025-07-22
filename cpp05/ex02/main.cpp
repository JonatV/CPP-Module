/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:42 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 17:59:05 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>
#include <math.h>

int	main()
{
	Bureaucrat employee("Ventouse", 10);  // Calls parameterized constructor
	std::cout << employee << std::endl;
	
	ShrubberyCreationForm shrubbery("Rigby_Garden");
	std::cout << shrubbery;
	try
	{
		shrubbery.beSigned(employee);
		shrubbery.execute(employee);
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const AForm::GradeTooHighException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const AForm::GradeTooLowException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const AForm::NotExecutedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const AForm::FormNotSignedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception Global: " << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------------------------\n" << std::endl;

	RobotomyRequestForm robot("Donald");
	std::cout << robot;
	try
	{
		robot.beSigned(employee);// todo error when not signed
		robot.execute(employee);
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const AForm::GradeTooHighException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const AForm::GradeTooLowException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const AForm::FormNotSignedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const AForm::NotExecutedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception Global: " << e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------------------------\n" << std::endl;

	PresidentialPardonForm president("Tanguy");
	std::cout << president;
	std::cout << employee;
	try
	{
		employee.incrementGrade();
		employee.incrementGrade();
		employee.incrementGrade();
		employee.incrementGrade();
		employee.incrementGrade();
		president.beSigned(employee);
		president.execute(employee);
		employee.executeForm(president);
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception Bureaucrat: " << myException.what() << std::endl;
	} catch (const AForm::GradeTooHighException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const AForm::GradeTooLowException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const AForm::FormNotSignedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (const AForm::NotExecutedException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception Global: " << e.what() << std::endl;
	}

	return 0;
}
