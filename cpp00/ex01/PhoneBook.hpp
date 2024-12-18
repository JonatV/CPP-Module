/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:09:56 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/18 10:09:57 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

#define B "\e[1m"
#define BRED "\e[1;31m"
#define GREEN "\e[32m"
#define DARK "\e[2m"
#define N "\e[0m"
#define TAB ""
#define BOX "| \t"
#define XOB "\t |"


class PhoneBook
{
	private:
		static const int	MAX_PROFILES = 8;
		int					current_profile_number;
		int					total_profiles;
		Contact				array_contact[MAX_PROFILES];

		void				display_add_contact_header();
		void				display_search_contact_header();
		void				display_contact_list();
		bool				add_contact_input_retrieving(std::string *name, std::string *last, std::string *nickname, std::string *phone, std::string *secret);

	public:
		PhoneBook();
		~PhoneBook();
		bool	add_contact();
		bool	search_contact();
		void	print_user_choice(int index_choosen);
		bool	has_space_for_new_contact();
};

#endif
