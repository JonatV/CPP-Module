/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:05 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 12:06:04 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>
#include <sstream>

Brain::Brain() {
	std::cout << "\e[2mDefault constructor Brain called\e[0m" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << "Idea " << i;
		this->ideas[i] = ss.str();
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "\e[2mCopy constructor Brain called\e[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain::~Brain() {
	std::cout << "\e[2mDestructor Brain called\e[0m" << std::endl;
}

Brain &Brain::operator=(const Brain &other){
	std::cout << "\e[2mAssignation Brain operator called\e[0m" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100)
	{
		std::cerr << "Error: Index out of bounds in getIdea" << std::endl;
		return ("");
	}
	return (this->ideas[index]);
}

void Brain::setIdea(const std::string &idea, int index) {
	if (index < 0 || index >= 100)
	{
		std::cerr << "Error: Index out of bounds in setIdea" << std::endl;
		return;
	}
	this->ideas[index] = idea;
}
