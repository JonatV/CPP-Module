/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:59:24 by jveirman          #+#    #+#             */
/*   Updated: 2025/02/26 16:21:43 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

#define RESET			"\033[0m"
#define RED				"\033[31m"
#define GREEN			"\033[1;32m"
#define YELLOW			"\033[1;33m"
#define BLUE			"\033[1;34m"
#define MAGENTA			"\033[1;35m"
#define CYAN			"\033[1;36m"
#define WHITE			"\033[1;37m"

int	main(void)
{
	Data original;
	uintptr_t raw;

	original.num01 = 19;
	original.num02 = 111111111;
	original.c = 'J';
	original.b = true;
	
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "\t" << YELLOW "ORIGINAL STRUCT" RESET << std::endl;
	std::cout << "\t" << "num01\t=\t" << original.num01 << std::endl;
	std::cout << "\t" << "num02\t=\t" << original.num02 << std::endl;
	std::cout << "\t" << "char\t=\t" << original.c << std::endl;
	std::cout << "\t" << "boolean\t=\t" << (original.b  ? "true" : "false") << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << std::endl;

	raw = Serialization::serialize(&original);
	std::cout << "Raw serialized struct num : "<< MAGENTA << raw << RESET<< std::endl << std::endl;

	Data *deserializeRaw = Serialization::deserialize(raw);
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "\t" << YELLOW "Serialize -> deserialize struct" RESET << std::endl;
	std::cout << "\t" << "num01\t=\t" << deserializeRaw->num01 << std::endl;
	std::cout << "\t" << "num02\t=\t" << deserializeRaw->num02 << std::endl;
	std::cout << "\t" << "char\t=\t" << deserializeRaw->c << std::endl;
	std::cout << "\t" << "boolean\t=\t" << (deserializeRaw->b  ? "true" : "false") << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	return (0);
}
