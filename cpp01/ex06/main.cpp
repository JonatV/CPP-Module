/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:51:49 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/19 12:59:14 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl	harl;
		harl.complain(argv[1]);
	}
	else
		std::cout << "Use this program with argument.\nAvailable options : DEBUG - INFO - WARNING - ERROR" << std::endl;
	return (0);
}
