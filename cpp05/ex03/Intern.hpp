/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:18 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:59:18 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
class Form;

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
		Form *makeForm(std::string form_type, std::string target);
	// Getters
		
	// Setters
		
};

#endif
