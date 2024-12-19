/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:54:39 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:54:40 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool _isGuard;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &);
		ScavTrap(std::string);

		~ScavTrap();
		
		ScavTrap &operator=(const ScavTrap &);

		void attack(const std::string &);
		void guardGate();
};

#endif
