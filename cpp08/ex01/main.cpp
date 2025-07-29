#include "span.hpp"

#define SPAN_SIZE 10

int main() {
	std::srand(std::time(0));




	  /////////////////////////////////////
	 //   TEST WITH TWO NORMAL ARRAYS   //
	/////////////////////////////////////
	Span sp = Span(SPAN_SIZE);
	std::vector<int> numbers_sp;
	for (size_t i = 0; i < SPAN_SIZE; ++i) {
		numbers_sp.push_back(std::rand() % 1000000);
	}
	try {
		sp.addNumber(numbers_sp.begin(), numbers_sp.end());
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}
	Span sp2 = sp;
	try {
		sp2.addNumber(100000);
	} catch(const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	sp.printSet(YELLOW, "sp");
	sp2.printSet(PURPLE, "sp2");
	std::cout << std::endl;

	try {
		std::cout << YELLOW << "Longest span of sp: \t" << sp.longestSpan() << RESET << std::endl;
		std::cout << PURPLE << "Longest span of sp2: \t" << sp2.longestSpan() << RESET << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << YELLOW << "Shortest span of sp: \t" << sp.shortestSpan() << RESET << std::endl;
		std::cout << PURPLE << "Shortest span of sp2: \t" << sp2.shortestSpan() << RESET << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;



	  //////////////////////////////////
	 //   FAIL TEST WITH SIZE OF 1   //
	//////////////////////////////////
	std::cout << "Testing exception handling for Span with size 1:" << RESET << std::endl;
	Span spFail = Span(1);
	try {
		for (size_t i = 0; i < SPAN_SIZE; ++i) {
			spFail.addNumber(42 + i);
		}
	} catch (const std::out_of_range &e) {
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}
	spFail.printSet(RED, "spFail");
	std::cout << std::endl;

	try {
		std::cout << RED << "Longest span of spFail: \t" << spFail.longestSpan() << RESET << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << RED << "Shortest span of spFail: \t" << spFail.shortestSpan() << RESET << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;




	  /////////////////////////////////////////
	 //   Testing span with large numbers   //
	/////////////////////////////////////////
	std::cout << "Testing absurd range of numbers:" << std::endl;
	Span spAbsurd = Span(30000);
	// create a vector with a range of numbers
	std::vector<int> numbers_absurd;
	for (int i = 0; i < 30000; ++i) {
		numbers_absurd.push_back(std::rand() % __INT_MAX__);
	}
	try {
		spAbsurd.addNumber(numbers_absurd.begin(), numbers_absurd.end());
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << PURPLE << "Size of spAbsurd: \t\t" << spAbsurd.getSetSize() << RESET << std::endl;
	try {
		std::cout << PURPLE << "Longest span of spAbsurd: \t" << spAbsurd.longestSpan() << RESET << std::endl;
		std::cout << PURPLE << "Shortest span of spAbsurd: \t" << spAbsurd.shortestSpan() << RESET << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
