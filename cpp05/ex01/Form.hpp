/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:19 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 16:38:20 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form
{
	private:
		static const int	_maxGrade = 1;
		static const int	_minGrade = 150;
		const std::string	_name;
		const int			_executionGrade;
		const int			_signedGrade;
		bool				_isSigned;
	public:
	// Constructor
		Form();

	// Parameterized constructor
		Form(std::string const &name, int executionGrade, int signedGrade);
	// Copy constructor
		Form(Form const &);
		
	// Destructor
		~Form();
		
	// Overloads
		Form	&operator=(Form const &);
		
	// Member functions
		void	beSigned(const Bureaucrat &);
		void	beExecuted(const Bureaucrat &);
	// Getters
		std::string const &getName() const;
		bool	getIsSigned() const;
		int		getSignedGrade() const;
		int		getExecGrade() const;

	// Setters
		void	setIsSigned(bool);
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

// non-member overload <<
std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif
