/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:18:11 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 13:26:54 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/AMateria.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"

int	main(void)
{
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	std::cout << ice->getType() << std::endl;
	std::cout << cure->getType() << std::endl;


	delete ice;
	delete cure;
	return (0);
}
