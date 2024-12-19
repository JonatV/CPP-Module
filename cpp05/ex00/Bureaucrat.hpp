/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:01 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:58:01 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define RESET			"\033[0m"
#define RED				"\033[31m"
#define GREEN			"\033[1;32m" 
#define YELLOW			"\033[4;33m"
#define BLUE			"\033[1;34m"
#define MAGENTA			"\033[1;35m"
#define CYAN			"\033[1;36m"
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
		friend std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
		
	// Member functions
		void	incrementGrade();
		void	decrementGrade();
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
};

#endif
