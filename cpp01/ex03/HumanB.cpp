/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:50:54 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:50:56 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string n) : name(n) {};
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
