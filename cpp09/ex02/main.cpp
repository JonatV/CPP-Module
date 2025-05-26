#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, const char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
		return 1;
	}
	PmergeMe	pmerge(argv + 1, argv + argc);

	return 0;
}
