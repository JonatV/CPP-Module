/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:50:48 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:50:49 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <string>


/*
* Cannot have a reference &weapon when declare by reference MUST initialized it
* A referenc (&) cannot be reassign to another one. It's fixed.
* As we wont initialize the Weapon at the construct, we need to be able to have it empty
* We thus use a pointer that can be set to null. Till we have a setWeapon action.
*/
class HumanB{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string n);
		~HumanB();
		void setWeapon(Weapon &w);
		void attack();
};

#endif
