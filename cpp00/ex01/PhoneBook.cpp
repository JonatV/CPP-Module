/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:09:48 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:43:56 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook() : current_profile_number(0), total_profiles(0)
{
}

PhoneBook::~PhoneBook()
{
}

/*--------------------------------------------------*/
/*-------------- ADD CONTACT FUNCTIONS -------------*/
/*--------------------------------------------------*/

bool PhoneBook::has_space_for_new_contact()
{
	return (current_profile_number < MAX_PROFILES ? true : false);
}

void	PhoneBook::display_add_contact_header()
{
	std::cout << TAB "+-------------------------------------------+" << std::endl;
	std::cout << TAB BOX "	ADD CONTACT		    |" << std::endl;
	std::cout << TAB BOX "Number of current profile : 	" << (current_profile_number + 1) << "   |" << std::endl;
	std::cout << TAB "+-------------------------------------------+" << std::endl;
}

bool PhoneBook::add_contact_input_retrieving(std::string *name, std::string *last, std::string *nickname, std::string *phone, std::string *secret)
{
	std::cout << TAB BOX "Enter the first name ";
	if(!get_and_check_input(name, add_contact_process))
		return (false);
	std::cout << TAB BOX "Enter the last name ";
	if(!get_and_check_input(last, add_contact_process))
		return (false);
	std::cout << TAB BOX "Enter the nickname ";
	if(!get_and_check_input(nickname, add_contact_process))
		return (false);
	std::cout << TAB BOX "Enter the phone number ";
	if(!get_and_check_input(phone, add_contact_process))
		return (false);
	std::cout << TAB BOX "Enter the " DARK "darkest secret" N " ";
	if(!get_and_check_input(secret, add_contact_process))
		return (false);
	std::cout << TAB BOX GREEN "New contact correctly added." N<< std::endl;
	std::cout << TAB "+------------------------------------------------+" << std::endl;
	return (true);
}

bool	PhoneBook::add_contact()
{
	std::string name, last, nickname, phone, secret;

	if (!has_space_for_new_contact())
		current_profile_number = 0;
	display_add_contact_header();
	if (!add_contact_input_retrieving(&name, &last, &nickname, &phone, &secret))
		return (false);
	this->array_contact[current_profile_number].setName(name);
	this->array_contact[current_profile_number].setLast(last);
	this->array_contact[current_profile_number].setNickname(nickname);
	this->array_contact[current_profile_number].setPhone(phone);
	this->array_contact[current_profile_number].setSecret(secret);
	current_profile_number++;
	if (total_profiles < 8)
		total_profiles++;
	sleep(1);
	return (true);
}

/*--------------------------------------------------*/
/*------------ SEARCH CONTACT FUNCTIONS ------------*/
/*--------------------------------------------------*/
void	PhoneBook::print_user_choice(int	index_choosen)
{
	Contact &profile = this->array_contact[index_choosen - 1];

	std::cout << TAB B << "Profile ID: " N TAB << index_choosen << std::endl;
	std::cout << TAB B << "First Name: " N TAB << profile.getName() << std::endl;
	std::cout << TAB B << "Last Name: " N TAB << profile.getLast() << std::endl;
	std::cout << TAB B << "Nickname: " N TAB << profile.getNickname() << std::endl;
	std::cout << TAB B << "Phone: " N TAB TAB << profile.getPhone() << std::endl;
	std::cout << TAB DARK << "Darkest Secret: " << profile.getSecret() << N << std::endl;
}

bool	PhoneBook::user_choose_index_and_check(int	*index_choosen)
{
	std::string	buffer;
	while (true)
	{
		std::cout << TAB;
		if (!get_and_check_input(&buffer, search_process))
			return (false); 
		if (buffer.empty())
		{
			std::cout << TAB BRED "The input must contains something." N << std::endl;
			continue;
		}
		if (buffer.length() > 1)
		{
			std::cout << TAB BRED "The input must be a single digit." N << std::endl;
			continue;
		}
		if (!std::isdigit(buffer[0]))
		{
			std::cout << TAB BRED "Invalid input: not a number" N << std::endl;
			continue;
		}
		*index_choosen = buffer[0] - '0';
		if (*index_choosen > total_profiles || *index_choosen < 1)
			std::cout << TAB BRED "This number isn't in the valid range. ->" N << *index_choosen << std::endl;
		else
			return (true);
	}
}

void	PhoneBook::display_search_contact_header()
{
	std::cout << TAB "+-------------------------------------------+" << std::endl;
		std::cout << TAB "|		SEARCH CONTACT		    |" << std::endl;
		std::cout << TAB "|	Enter the profile ID to see info    |" << std::endl;
		std::cout << TAB "+-------------------------------------------+" << std::endl;
		std::cout << TAB "|" << std::setw(10) << "id" << "|" << std::setw(10) << "Firstname" << "|" << std::setw(10) << "Lastname" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
		std::cout << TAB "+----------+----------+----------+----------+" << std::endl;
}

void	PhoneBook::display_contact_list()
{
	int	i;
	std::string name, last, nickname, phone, secret;
	
	i = 0;
	while (i < total_profiles)
	{
		name = this->array_contact[i].getName();
		last = this->array_contact[i].getLast();
		nickname = this->array_contact[i].getNickname();
		if (name.length() > 9)
			name = name.substr(0, 9) + ".";
		if (last.length() > 9)
			last = last.substr(0, 9) + ".";
		if (nickname.length() > 9)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << TAB "|" << std::setw(10) << i + 1 << "|" << std::setw(10) << name << "|" << std::setw(10) << last << "|" << std::setw(10) << nickname << "|" << std::endl;
		i++;
	}
	std::cout << TAB "+-------------------------------------------+" << std::endl;
}

bool PhoneBook::search_contact()
{
	int	id;

	if (current_profile_number == 0)
		return (std::cout << BYEL "No profiles yet to be displayed." N << std::endl, sleep(2), true);
	else
		display_search_contact_header();
	display_contact_list();
	if (!user_choose_index_and_check(&id))
		return (false);
	system("clear");
	print_user_choice(id);
	std::cout << "\nPress enter to continue";
	getchar();
	return (true);
}
