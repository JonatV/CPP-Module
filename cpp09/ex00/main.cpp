#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}
	BitcoinExchange bitcoinExchange;
	try {
		bitcoinExchange.dbHandler();
		bitcoinExchange.inputHandler(argv[1]);
	} catch (const std::ifstream::failure &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	} catch (const std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
