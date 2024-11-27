/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:58:54 by jveirman          #+#    #+#             */
/*   Updated: 2024/11/25 12:01:39 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"

bool	get_and_check_input(std::string *buffer, t_token token)
{
	using std::cout;
	bool	first_loop;

	first_loop = true;
	while (true)
	{
		if (first_loop)
			cout << "> ";
		else if (token == add_contact_process)
			cout << "|	> ";
		else
			cout << "> ";
		buffer->clear();
		if (!std::getline(std::cin, *buffer))
		{
			if (token == add_contact_process)
				cout << "|	";
			cout << "Error reading input, program is exiting" << std::endl;
			return (false);
		}
		if (buffer->empty())
		{
			if (token == add_contact_process)
				cout << "|	";
			cout << BRED "The input must contains something." N << std::endl;
		}
		else
			break ;
		first_loop = false;
	}
	return (true);
}

int main(void)
{
	std::string	buffer;
	PhoneBook	phonebook;

	while (true)
	{
		system("clear");
		std::cout << "\nCommand valid : ADD, SEARCH and EXIT" << std::endl;
		if (!get_and_check_input(&buffer, main_process))
			return (1);
		if (buffer == "ADD")
		{
			if(!phonebook.add_contact())
				return (1);
			system("clear");
		}
		else if (buffer == "SEARCH")
		{
			if(!phonebook.search_contact())
				return (1);
		}
		else if (buffer == "EXIT")
		{
			std::cout << "Bye" << std::endl; // todo: merge the text and return
			return (0);
		}
	}
	return 0;
}
