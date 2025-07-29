#include "span.hpp"
#include <iostream>
#include <limits.h>
#include <vector>
#include <numeric>
#include <algorithm>

Span::Span(unsigned int n) : _size(n) {
}

Span::Span(const Span &src) : _size(src._size), _set(src._set) {
}

Span::~Span() {
}

Span &Span::operator=(const Span &src) {
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

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	for (std::vector<int>::iterator it = begin; it != end; ++it) {
		if (_set.size() >= _size) {
			throw std::out_of_range("Span is full");
		}
		_set.insert(*it);
	}
}

int Span::longestSpan() const {
	if (_set.size() < 2) throw std::out_of_range("Not enough numbers (2 minimum)");
	int min = *_set.begin();
	int max = *_set.rbegin();
	return max - min;
}

int Span::shortestSpan() const {
	if (_set.size() < 2) throw std::out_of_range("Not enough numbers (2 minimum)");
	std::vector<int> diffs(_set.size());
	std::adjacent_difference(_set.begin(), _set.end(), diffs.begin());

	return *std::min_element(diffs.begin() + 1, diffs.end());
}

unsigned int Span::getSetSize() const {
	return _set.size();
}

void Span::printSet(std::string color, std::string name) const {
	std::cout << color << "Set contents of " << name << ": \t";
	for (std::multiset<int>::const_iterator it = _set.begin(); it != _set.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
}
