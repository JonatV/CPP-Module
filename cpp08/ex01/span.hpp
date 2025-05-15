#ifndef SPAN_HPP
#define SPAN_HPP
#include <set>
class Span {
	public:
		Span(unsigned int);
		Span(const Span &);
		~Span();
		Span &operator=(const Span &);
		void addNumber(int);
		int longestSpan() const;
		int shortestSpan() const;

		unsigned int getSetSize() const;
		void printSet() const;
	private:
		Span();
		unsigned int _size;
		std::multiset<int> _set;
};
#endif
