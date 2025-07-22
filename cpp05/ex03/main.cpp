/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:17 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 18:40:38 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>
#include <string>
#include <math.h>

int	main()
{
	Bureaucrat employee("Jo", 1);
	Intern	slave1;
	Intern slave2(slave1);

	try
	{
		AForm *formTest = slave1.makeForm("shrubbery creation", "MyGarden");
		std::cout << *formTest;
		AForm *secondTest = slave2.makeForm("presidential pardon", "Scavtrap");
		std::cout << *secondTest;
		// AForm *failForm = slave1.makeForm("Fail Form", "tututu"); // toggle comment to test unknown form

		formTest->beSigned(employee);
		secondTest->beSigned(employee);
		
		employee.executeForm(*formTest);
		employee.executeForm(*secondTest);
		delete formTest;
		delete secondTest;
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
	} catch (const AForm::FormTypeUnknownException &myException){
		std::cerr << "Exception Form: " << myException.what() << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception Global: " << e.what() << std::endl;
	}
	return 0;
}
