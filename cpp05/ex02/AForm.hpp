/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:58:45 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 17:22:50 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		AForm();

	// Parameterized constructor
		AForm(std::string const &name, int executionGrade, int signedGrade);
	// Copy constructor
		AForm(AForm const &);
		
	// Destructor
		virtual ~AForm();
		
	// Overloads
		AForm	&operator=(AForm const &);
		
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
};

std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif
