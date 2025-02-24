/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:57:09 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:57:09 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	inventory[4];

	public:
	//constructors
	Character();
	Character(const std::string &name);
	Character(const Character &);

	//destructors
	~Character();

	//overloaded operators
	Character &operator=(const Character &);

	//methods

	//getters

	//setters

}

#endif
