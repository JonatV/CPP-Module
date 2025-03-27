/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:18:11 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/27 04:47:19 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/AMateria.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"
#include "inc/Character.hpp"
#include "inc/MateriaSource.hpp"

int	main(void)
{
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria *ice2 = new Ice();
	AMateria *iceBobClone = new Ice();
	AMateria *cure2 = new Cure();
	AMateria *cure3 = new Cure();
	AMateria *cureBobClone = new Cure();

	ICharacter *bob = new Character("Bob");
	ICharacter *bobClone = new Character("BobClone");
	ICharacter *gandalf = new Character("Gandalf");

	src->showBook();
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	bob->equip(ice2);
	bob->equip(cure2);
	bob->equip(cure3);
	bob->use(0, *gandalf);
	bob->use(2, *gandalf);

	bobClone->equip(iceBobClone);
	bobClone->equip(cureBobClone);
	bobClone->unequip(0);
	bobClone->use(1, *bob);
	bobClone->showInventory();

	*static_cast<Character*>(bobClone) = *static_cast<Character*>(bob);
	bobClone->use(0, *gandalf);
	bobClone->showInventory();
	bob->showInventory();
	
	delete bobClone;
	delete bob;
	delete gandalf;
	delete src;
	return (0);
}
