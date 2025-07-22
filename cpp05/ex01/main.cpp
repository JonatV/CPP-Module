/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:18 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 16:50:58 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>

int	main()
{
	try {
		Bureaucrat c("Jo", 10);  // Calls parameterized constructor
		std::cout << c;
		Form form1("---Destroy the company---", 10, 10);
		std::cout << "Form title: "<< form1.getName() << std::endl;
		std::cout << (form1.getIsSigned() ? "The doc is" GREEN " signed" RESET : "The doc is " RED "NOT signed" RESET) << std::endl;
		std::cout << "To signed this doc, employee must be at least grade: " CYAN << form1.getSignedGrade() << RESET << std::endl << std::endl;
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
	} catch (std::exception & e) {
		std::cerr << "Exception Global: " << e.what() << std::endl;
	}
	return 0;
}
