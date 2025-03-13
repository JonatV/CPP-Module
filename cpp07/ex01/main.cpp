/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:48:09 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/13 15:18:51 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void	damnNumbers(int n)
{
	std::cout << "Damn number\t\t[" << n << "]" << std::endl;
}

void	damnGoodOldChar(char c)
{
	std::cout << "A good old damn char\t[" << c << "]" << std::endl;
}

void	damnString(std::string s)
{
	std::cout << "A long damn string\t[" << s << "]" << std::endl;
}

int	main(void)
{
	int			n[6] = {42, 19, 1337, 21, 0, 1};
	char		c[4] = {'d', 'a', 'm', 'n'};
	std::string	s[3] = {"Oui", "oui", "baguette"};

	iter(n, sizeof(n) / sizeof(n[0]), damnNumbers);
	iter(c, sizeof(c) / sizeof(c[0]), damnGoodOldChar);
	iter(s, sizeof(s) / sizeof(s[0]), damnString);
	return (0);
}
