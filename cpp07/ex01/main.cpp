/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:48:09 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/19 10:29:54 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

#define P "\e[35m"
#define Y "\e[33m"
#define R "\e[31m"
#define N "\e[0m"

void	damnNumbers(int n)
{
	std::cout << P "Damn number\t\t[" << n << "]" N << std::endl;
}

void	damnGoodOldChar(char c)
{
	if (c >= 32 && c <= 126)
		std::cout << R "A good old damn char\t[" << c << "]" N << std::endl;
	else
		std::cout << R "A good old damn char\t[Non displayable]" N << std::endl;
}

void	damnString(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] < 32 || s[i] > 126)
		{
			std::cout << Y "A long damn string\t[Non displayable]" N << std::endl;
			return ;
		}
	}
	std::cout << Y "A long damn string\t[" << s << "]" N<< std::endl;
}

int	main(void)
{
	int			n[6] = {42, 19, 1337, 21, 0, 1};
	char		c[4] = {'d', 'a', 'm', 'n'};
	std::string	s[3] = {"Oui", "oui", "baguette"};

	iter(n, sizeof(n) / sizeof(n[0]), damnGoodOldChar);
	iter(n, sizeof(n) / sizeof(n[0]), damnNumbers);
	iter(c, sizeof(c) / sizeof(c[0]), damnGoodOldChar);
	iter(s, sizeof(s) / sizeof(s[0]), damnString);
	return (0);
}
