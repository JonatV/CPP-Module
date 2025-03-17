/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:51:25 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/17 13:09:39 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "Wrong command call (filename string_to_replace new_string)" << std::endl;
	else
	{
		Sed strEditor(argv[2], argv[3], argv[1]);
		if (!strEditor.startReplacement())
			return (1);
		std::cout << "Modified text can be found in : \e[1;35m" << argv[1] << ".replace\e[0m " << std::endl;
	}
	return (0);
}
