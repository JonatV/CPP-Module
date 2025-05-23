#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

bool Date::operator<(const Date &other) const {
	if (this->year != other.year)
		return (this->year < other.year);
	if (this->month != other.month)
		return (this->month < other.month);
	return (this->day < other.day);
}

BitcoinExchange::BitcoinExchange() : _dbFileName("data.csv"){}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::dbHandler() {
	std::ifstream dbFile(_dbFileName.c_str());
	if (!dbFile.is_open()) {
		throw std::ifstream::failure("Error: Could not open the database file.");
	}
	if (dbFile.peek() == EOF) {
		throw std::ifstream::failure("Error: The database file is empty.");
	}
	std::string line;
	while (std::getline(dbFile, line)) {
		if (line.empty()) {
			continue;
		}
		std::pair<std::string, double> data = splitLine(line, ',');
		std::cout << "Date: " << data.first << ", Value: " << data.second << std::endl;
	}
	dbFile.close();
}

std::pair<std::string, double> BitcoinExchange::splitLine(const std::string &line, char delimiter) {
	std::string dateStr;
	std::string valueStr;
	size_t pos = line.find(delimiter);
	if (pos == std::string::npos) {
		throw std::invalid_argument("Error: Invalid line format.");
	}
	dateStr = line.substr(0, pos);
	valueStr = line.substr(pos + 1);
	if (dateStr.empty() || valueStr.empty()) {
		throw std::invalid_argument("Error: Invalid line format.");
	}
	// check format of dateStr
	if (dateStr.size() != 10) {
		throw std::invalid_argument("Error: Invalid date format.");
	}
	for (size_t i = 0; i < dateStr.size(); ++i) {
		if (i == 4 || i == 7) {
			if (dateStr[i] != '-') {
				throw std::invalid_argument("Error: Invalid date format.");
			}
		} else if (!isdigit(dateStr[i])) {
			throw std::invalid_argument("Error: Invalid date format.");
		}
	}
	// check format of valueStr
	int dotCount = 0;
	int numberAfterDot = 0;
	bool afterDot = false;
	
	for (size_t i = 0; i < valueStr.size(); ++i) {
		char c = valueStr[i];
		std::cout << "[" << i << "] = '" << c << "' (" << static_cast<int>(c) << ")\n";
		if (c == '.') {
			dotCount++;
			if (dotCount > 1) {
				throw std::invalid_argument("Error: Invalid value format.");
			}
			afterDot = true;
		}
		else if (!isdigit(c)) {
			throw std::invalid_argument("Error: Invalid value format.");
		}
		else if (afterDot) {
			numberAfterDot++;
			if (numberAfterDot > 2) {
				throw std::invalid_argument("Error: Invalid value format.");
			}
		}
	}
	char *endptr;
	double value = strtod(valueStr.c_str(), &endptr);
	if (*endptr != '\0') {
		throw std::invalid_argument("Error: Invalid value format.");
	}
	std::cout << RED "valueStr: [" << valueStr.c_str() << "]" N << std::endl;
	std::cout << RED "value: " << value << N << std::endl;
	return (std::make_pair(dateStr, value));
}
