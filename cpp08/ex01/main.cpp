#include "span.hpp"

#include <iostream>
#include <set>

int main() {
	// Span sp = Span(50000);
	// int i = -10000;
	Span sp = Span(6);

	try {
		// while (sp.getSetSize() < 50000) {
		// 	sp.addNumber(i++);
		// }

		sp.addNumber(100);
		sp.addNumber(-1234);
		sp.addNumber(124);
		sp.addNumber(4);
		sp.addNumber(322);
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}

	Span sp2 = sp;
	sp2.addNumber(100000);
	sp.printSet();
	sp2.printSet();

	try {
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
