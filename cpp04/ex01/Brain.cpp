/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:05 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:56:07 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain() {
	std::cout << "\e[2mDefault constructor Brain called\e[0m" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "\e[2mCopy constructor Brain called\e[0m" << std::endl;
	*this = other;
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
	return *this;
}

std::string Brain::getIdea(int index) const {
	return this->ideas[index];
}

void Brain::setIdea(const std::string &idea, int index) {
	this->ideas[index] = idea;
}
