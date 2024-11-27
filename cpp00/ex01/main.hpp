#ifndef MAIN_HPP
#define MAIN_HPP
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <sstream>

typedef enum s_token
{
	search_process,
	add_contact_process,
	main_process
}	t_token;

bool	get_and_check_input(std::string *buffer, t_token token);

#endif
