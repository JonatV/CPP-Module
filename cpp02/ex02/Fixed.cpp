#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0) {
	// std::cout << "\e[2mDefault constructor called\e[0m" << std::endl;
	value = 0;
}

Fixed::~Fixed() {
	// std::cout << "\e[2mDestructor called\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &old_fixed) {
	// std::cout << "\e[2mCopy constructor called\e[0m" << std::endl;
	*this = old_fixed;
}

Fixed::Fixed(const int v)
{
	// std::cout << "\e[2mInt constructor called\e[0m" << std::endl;
	value = v << bits;
}

Fixed::Fixed(const float v)
{
	// std::cout << "\e[2mFloat constructor called\e[0m" << std::endl;
	value = roundf(v * (1 << bits));
}

Fixed &Fixed::operator=(const Fixed &old_fixed) {
	// std::cout << "\e[2mCopy assignment operator called\e[0m" << std::endl;
	value = old_fixed.value;
	return (*this);
}

int Fixed::getRawBits(void) const {
	// std::cout << "\e[2mgetRawBits member function called\e[0m" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "\e[2msetRawBits member function called\e[0m" << std::endl;
	value = raw;
}
// it's the reverse of the constructor that takes a float
float Fixed::toFloat(void) const {
	return ((float)value / (1 << bits));
}

// it's the reverse of the constructor that takes an int
int Fixed::toInt(void) const {
	return (value >> bits);
}
/* @link https://www.youtube.com/watch?v=BnMnozsSPmw
* this explain how to overload the << operator, common error and good practices (in depth)
*/
std::ostream &operator<<(std::ostream &COUT, const Fixed &fixed) {
	COUT << fixed.toFloat();
	return (COUT);
}

/////////////////////////////////
//     Comparison operators    //
/////////////////////////////////
bool Fixed::operator>(const Fixed &other) const {
	return(this->value > other.value);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->value != other.value);
}

/////////////////////////////////
//     Arithmetic operators    //
/////////////////////////////////
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result(this->toFloat() - other.toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.value == 0)
	{
		std::cerr << "Error: Division by zero!" << std::endl;
		return Fixed(0);
	}
	Fixed result(this->toFloat() / other.toFloat());
	return (result);
}

/////////////////////////////////
//     Increment operators     //
/////////////////////////////////

Fixed &Fixed::operator++(void) {
	this->value++;
	return (*this);
}

/* https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c
* post increment operator overloading paper with examples
*/
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->value++;
	return (temp);
}

Fixed &Fixed::operator--(void) {
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->value--;
	return (temp);
}

/////////////////////////////////
//     Min and Max functions   //
/////////////////////////////////

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.value < b.value)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.value < b.value)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.value > b.value)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.value > b.value)
		return (a);
	return (b);
}
