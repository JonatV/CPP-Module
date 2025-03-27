/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:18:11 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/27 03:14:11 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/AMateria.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"
#include "inc/Character.hpp"

int	main(void)
{
	AMateria *ice = new Ice();
	AMateria *ice2 = new Ice();
	AMateria *cure = new Cure();
	AMateria *cure2 = new Cure();
	AMateria *cure3 = new Cure();

	ICharacter *bob = new Character("Bob");

	bob->equip(ice);
	bob->equip(ice2);
	bob->equip(cure);
	bob->equip(cure2);
	bob->equip(cure3);

	delete bob;
	return (0);
}
