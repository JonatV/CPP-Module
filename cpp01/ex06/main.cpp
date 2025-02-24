/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:51:49 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:51:49 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		Harl	harl;
		harl.complain(argv[1]);
	}
	return (0);
}
