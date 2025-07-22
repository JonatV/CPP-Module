/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:00 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 16:09:24 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int	main()
{
	try {
		Bureaucrat a;  // Calls default constructor
		Bureaucrat b("Jo", 1);  // Calls parameterized constructor
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &myException) {
		std::cerr << "Exception: " << myException.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &myException) {
		std::cerr << "Exception: " << myException.what() << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception Global: " << e.what() << std::endl;
	}

	try {
		Bureaucrat c("Ventouse", 150);  // Calls parameterized constructor
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
		c.decrementGrade();
		std::cout << c << std::endl;
		c.decrementGrade(); // here, we go under the minimum grade must throw an exception
		} catch (const Bureaucrat::GradeTooHighException &myException) {
			std::cerr << "Exception: " << myException.what() << std::endl;
		} catch (const Bureaucrat::GradeTooLowException &myException) {
			std::cerr << "Exception: " << myException.what() << std::endl;
		} catch (std::exception & e) {
			std::cerr << "Exception Global: " << e.what() << std::endl;
		}
	return 0;
}
