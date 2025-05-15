#include "span.hpp"
#include <iostream>
#include <limits.h>

Span::Span(unsigned int n) : _size(n) {
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &src) : _size(src._size), _set(src._set) {
	std::cout << "Span copy constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

Span &Span::operator=(const Span &src) {
	std::cout << "Span assignment operator called" << std::endl;
	if (this != &src) {
		_size = src._size;
		_set = src._set;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_set.size() >= _size) throw std::out_of_range("Span is full");
	_set.insert(n);
}

int Span::longestSpan() const {
	if (_set.size() < 2) throw std::out_of_range("Not enough numbers (2 minimum)");
	int min = *_set.begin();
	int max = *_set.rbegin();
	return max - min;
}

int Span::shortestSpan() const {
	if (_set.size() < 2) throw std::out_of_range("Not enough numbers (2 minimum)");
	int minDiff = INT_MAX;
	std::multiset<int>::const_iterator iter = _set.begin(), next = iter;
	++next;
	for (; next != _set.end(); ++iter, ++next) {
		int diff = *next - *iter;
		if (diff < minDiff) minDiff = diff;
	}
	return minDiff;
}

unsigned int Span::getSetSize() const {
	return _set.size();
}

void Span::printSet() const {
	std::cout << "Set contents: ";
	for (std::multiset<int>::const_iterator it = _set.begin(); it != _set.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
