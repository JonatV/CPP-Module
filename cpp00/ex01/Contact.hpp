/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:09:29 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/18 10:09:31 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

#define BYEL "\e[1;33m"
#define UYEL "\e[4;33m"
#define N "\e[0m"
class Contact
{
	private:
		std::string	name;
		std::string	last;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
		
	public:
		Contact();
		~Contact();

		//Setters
		void	setName(std::string name);
		void	setLast(std::string last);
		void	setNickname(std::string nickname);
		void	setPhone(std::string phone);
		void	setSecret(std::string secret);
		//Getters
		std::string	getName(void);
		std::string	getLast(void);
		std::string	getNickname(void);
		std::string	getPhone(void);
		std::string	getSecret(void);
};

#endif
