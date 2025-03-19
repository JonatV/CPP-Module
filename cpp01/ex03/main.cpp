/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:50:43 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/19 10:13:20 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "iostream"

int main(void)
{
	{
		std::cout << "\e[36m";
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << "\e[33m";
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << "\e[32m";
		Weapon club = Weapon("crude spiked club");
		Weapon wok = Weapon("oily wok");
		HumanB Ken("Ken", club);
		Ken.attack();
		Ken.setWeapon(wok);
		Ken.attack();
		club.setType("some other type of club");
		Ken.setWeapon(club);
		Ken.attack();
	}
	return 0;
}
