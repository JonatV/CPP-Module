#ifndef SPAN_HPP
#define SPAN_HPP
#include <set>
#include <string>
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <vector>

#define PURPLE "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Span {
	public:
		Span(unsigned int);
		Span(const Span &);
		~Span();
		Span &operator=(const Span &);
		void addNumber(int);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int longestSpan() const;
		int shortestSpan() const;

		unsigned int getSetSize() const;
		void printSet(std::string color, std::string name) const;
	private:
		Span();
		unsigned int _size;
		std::multiset<int> _set;
};
#endif
