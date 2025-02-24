/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:45 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:58:46 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		static const int	_maxGrade = 1;
		static const int	_minGrade = 150;
		const std::string	_name;
		const int			_executionGrade;
		const int			_signedGrade;
		bool				_isSigned;
	protected:
		virtual void		executeAction() const = 0;
	public:
	// Constructor
		Form();

	// Parameterized constructor
		Form(std::string const &name, int executionGrade, int signedGrade);
	// Copy constructor
		Form(Form const &);
		
	// Destructor
		virtual ~Form();
		
	// Overloads
		Form	&operator=(Form const &);
		
	// Member functions
		void	beSigned(const Bureaucrat &);
		void	execute(const Bureaucrat &) const;

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NotExecutedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	// friends
		friend std::ostream	&operator<<(std::ostream &os, const Form &form);
	
};

#endif
