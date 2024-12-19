/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:57:05 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:57:06 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	private:

	public:
	// constructors
		Ice();
		Ice(const Ice &);
	
	// destructors
		~Ice();
	
	// overloaded operator
		Ice &operator=(const Ice &);

	// methods
		AMateria *clone() const override;
		void use(ICharacter &target) override;

	// getters

	// setters
};

#endif
