/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:50:54 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/17 12:47:23 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string n) : name(n){};
HumanB::HumanB(std::string n, Weapon &w) : name(n), weapon(&w){};
HumanB::~HumanB(){};

void	HumanB::attack(){
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their " << "very dangerous hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &w){
	weapon = &w;
}
