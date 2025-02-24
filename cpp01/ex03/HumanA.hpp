/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:50:57 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:50:58 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <string>

class HumanA{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string n, Weapon &w);
		~HumanA();
		void attack();
};

#endif
