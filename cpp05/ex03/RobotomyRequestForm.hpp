/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:12 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 18:26:29 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		static const int	_executionGrade = 45;
		static const int	_signedGrade = 72;
		const std::string	_target;
	protected:
		void				executeAction() const;
	public:
	// Constructor
		RobotomyRequestForm();

	// Parameterized constructor
		RobotomyRequestForm(std::string);

	// Copy constructor
		RobotomyRequestForm(const RobotomyRequestForm &);
		
	// Destructor
		~RobotomyRequestForm();
		
	// Overloads
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &);
		
	// Member functions
	// Getters
		std::string	getTarget() const;
};

#endif
