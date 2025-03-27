/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:53:48 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/27 03:17:33 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <list>

#define MAX_MATERIA 4

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[MAX_MATERIA];
		// unequipped materia will be register here
		// and will be delete in the destructor
		std::list<AMateria*> _unequipped;
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		~Character();
		Character	&operator=(const Character &other);

		// methods
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void showInventory() const;

		// getters
		std::string const & getName() const;
};

#endif
