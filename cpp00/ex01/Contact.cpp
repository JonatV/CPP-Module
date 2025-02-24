/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:09:20 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/18 10:09:21 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setName(std::string name)
{
	this->name = name;
}

void Contact::setLast(std::string last)
{
	this->last = last;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::setPhone(std::string phone)
{
	this->phone = phone;
}

void Contact::setSecret(std::string secret)
{
	this->secret = secret;
}

std::string	Contact::getName(void)
{
	return (this->name);
}

std::string	Contact::getLast(void)
{
	return (this->last);
}


std::string	Contact::getNickname(void)
{
	return (this->nickname);
}

std::string	Contact::getPhone(void)
{
	return (this->phone);
}

std::string	Contact::getSecret(void)
{
	return (this->secret);
}

