/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:51:47 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:51:48 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "\e[2mHarl constructor called \e[0m" << std::endl;
}

Harl::~Harl()
{
	std::cout << "\e[2mHarl destructor called \e[0m" << std::endl;
}

/*
* @link http://sitesimons.free.fr/C++2/A9.pdf
* Very clear and detailed explanation for pointers to member functions
*/
void Harl::complain(std::string level)
{
	int	i;
	int	pos;
	void (Harl::*ptrMF[]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"debug", "info", "warning", "error"};
	pos = -1;
	i = -1;
	while (++i < 4)
	{
		if (levels[i] == level)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)
		return (std::cout << "\e[1;31mError\e[0m: \e[1;31mUnknown danger level\e[0m" << std::endl, void());
	(this->*ptrMF[pos])();
}

void Harl::debug(void)
{
	std::cout << "\e[36mI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\e[0m" << std::endl;
}

void Harl::info(void)
{
	std::cout << "\e[32mI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\e[0m" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "\e[33mI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\e[0m" << std::endl;
}

void Harl::error(void)
{
	std::cout << "\e[31mThis is unacceptable ! I want to speak to the manager now.\e[0m" << std::endl;
}
