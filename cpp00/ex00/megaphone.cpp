/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:54:32 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/18 11:20:19 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int word = 1; word < argc; ++word)
		{
			for (int letter = 0; argv[word][letter]; ++letter)
				std::cout << static_cast<char>(toupper(argv[word][letter]));
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
