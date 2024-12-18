/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:09:39 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/18 10:09:43 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
