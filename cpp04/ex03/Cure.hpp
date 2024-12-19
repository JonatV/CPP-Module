/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:57:07 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:57:07 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	private:

	public:
	// constructors
		Cure();
		Cure(const Cure &);
	
	// destructors
		~Cure();
	
	// overloaded operator
		Cure &operator=(const Cure &);

	// methods
		AMateria *clone() const override;
		void use(ICharacter &target) override;

	// getters

	// setters
};

#endif
