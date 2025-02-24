/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:48:27 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:48:28 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
	if (n <= 0)
		return (NULL);
	Zombie *zombieHorde = new Zombie[n];
	for (int i = 0; i < n; i++)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}
