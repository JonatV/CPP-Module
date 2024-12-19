/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:54:44 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:54:45 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		bool _isHighFivesGuys;
	public:
		FragTrap();
		FragTrap(std::string);
		FragTrap(const FragTrap &);

		~FragTrap();

		FragTrap &operator=(const FragTrap &);
		void highFivesGuys();
};


#endif
