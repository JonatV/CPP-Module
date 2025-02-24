/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:51:04 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:51:05 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t) : type(t) {};
Weapon::~Weapon() {};

const std::string &Weapon::getType(){
	return (type);
}

void Weapon::setType(const std::string &t){
	this->type = t;
}
