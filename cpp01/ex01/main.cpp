/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:48:34 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:50:53 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int n, std::string name);

int	main()
{
	int n = 10;
	Zombie zombieStack("StackBrainEater");
	
	zombieStack.announce();
	std::cout << std::endl;
	Zombie *gang = zombieHorde(n, "LeakingSquad");
	for (int i = 0; i < n; i++)
		gang[i].announce();
	std::cout << std::endl;
	delete[] gang;
	return 0;
}
