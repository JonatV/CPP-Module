/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:21 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:58:21 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define RESET			"\033[0m"
#define RED				"\033[31m"
#define GREEN			"\033[1;32m" // form signed
#define YELLOW			"\033[1;33m" // form already signed
#define BLUE			"\033[1;34m"
#define MAGENTA			"\033[1;35m" // Title form
#define CYAN			"\033[1;36m" // grade
#define WHITE			"\033[37m"

class Bureaucrat
{
	private:
		static const int	_maxGrade = 1;
		static const int	_minGrade = 150;
		std::string const	_name;
		int					_grade;
	public:
	// Constructor
		Bureaucrat();

	// Parameterized constructor
		Bureaucrat(std::string const &, int);

	// Copy constructor
		Bureaucrat(const Bureaucrat &);
		
	// Destructor
		~Bureaucrat();
		
	// Overloads
		Bureaucrat	&operator=(const Bureaucrat &);
		
	// Member functions
		void	incrementGrade();
		void	incrementGrade(int);
		void	decrementGrade();
		void	decrementGrade(int);

	// Getters
		const std::string	&getName() const;
		int					getGrade() const;

	// Setters
		void	setGrade(int);

	// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	//friends
		friend std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
};

#endif
