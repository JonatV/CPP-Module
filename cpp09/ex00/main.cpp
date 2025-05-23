#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	(void)argv;
	(void)argc;
	// if (argc != 2) {
	// 	std::cerr << "Error: Incorrect number of arguments." << std::endl;
	// 	return 1;
	// }

	
	BitcoinExchange bitcoinExchange;
	try {
		bitcoinExchange.dbHandler();
	} catch (const std::ifstream::failure &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	} catch (const std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
