/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:57:10 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:57:11 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria
{
	protected:
		std::string _type;
	public:
	// constructor
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &);

	// destructor
		~AMateria();
		
	// Overloaded Operator
		AMateria &operator=(const AMateria &);

	// Methods
		virtual AMateria *clone() const =0;
		virtual void use(ICharacter &target); // ?????

	// getters
		std::string const &getType() const; // returns the materia type
};

#endif
