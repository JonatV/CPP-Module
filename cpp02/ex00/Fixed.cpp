/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:52:21 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:53:07 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0) {
	std::cout << "\e[2mDefault constructor called\e[0m" << std::endl;
	value = 0;
}

Fixed::~Fixed() {
	std::cout << "\e[2mDestructor called\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &old_fixed) {
	std::cout << "\e[2mCopy constructor called\e[0m" << std::endl;
	*this = old_fixed;
}

Fixed &Fixed::operator=(const Fixed &old_fixed) {
	std::cout << "\e[2mAssignation operator called\e[0m" << std::endl;
	value = old_fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "\e[2mgetRawBits member function called\e[0m" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "\e[2msetRawBits member function called\e[0m" << std::endl;
	value = raw;
}
