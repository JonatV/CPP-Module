/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:53:03 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/17 19:49:20 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0) {
	std::cout << "\e[2mDefault constructor called\e[0m" << std::endl;
	value = 0;
}

Fixed::~Fixed() {
	std::cout << "\e[2mDestructor called\e[0m" << std::endl;
}

Fixed::Fixed(const int v)
{
	std::cout << "\e[2mInt constructor called\e[0m" << std::endl;
	value = v << bits; // like doing v * pow(2, bits)
}

Fixed::Fixed(const float v)
{
	std::cout << "\e[2mFloat constructor called\e[0m" << std::endl;
	value = roundf(v * (1 << bits));
}

Fixed::Fixed(const Fixed &old_fixed) {
	std::cout << "\e[2mCopy constructor called\e[0m" << std::endl;
	*this = old_fixed;
}

Fixed &Fixed::operator=(const Fixed &old_fixed) {
	std::cout << "\e[2mCopy assignment operator called\e[0m" << std::endl;
	value = old_fixed.value;
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

// it's the reverse of the constructor that takes a float
// we basically divide the value by 256 (2^8)
float Fixed::toFloat(void) const {
	return ((float)value / (1 << bits));
}

// it's the reverse of the constructor that takes an int
// we shift to the right
int Fixed::toInt(void) const {
	return (value >> bits);
}

/* @link https://www.youtube.com/watch?v=BnMnozsSPmw
* this explain how to overload the << operator, common error and good practices (in depth)
*/
std::ostream &operator<<(std::ostream &cout, const Fixed &fixed) {
	cout << fixed.toFloat();
	return (cout);
}

