/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:18 by jveirman          #+#    #+#             */
/*   Updated: 2025/07/22 18:29:08 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
class AForm;

class Intern
{
	private:
		
	public:
	// Constructor
		Intern();

	// Parameterized constructor
		
	// Copy constructor
		Intern(const Intern &);
		
	// Destructor
		~Intern();
		
	// Overloads
		Intern	&operator=(const Intern &);
		
	// Member functions
		AForm *makeForm(std::string form_type, std::string target);
	// Getters
		
	// Setters
		
};

#endif
