#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

bool Date::operator<(const Date &other) const {
	if (this->year != other.year)
		return (this->year < other.year);
	if (this->month != other.month)
		return (this->month < other.month);
	return (this->day < other.day);
}

bool Date::operator==(const Date &other) const {
	if (this->year != other.year)
		return (false);
	if (this->month != other.month)
		return (false);
	if (this->day != other.day)
		return (false);
	return (true);
}

BitcoinExchange::BitcoinExchange() : _currentLine(0), _dbFileName("data.csv"){
	_defaultDate.year = 0;
	_defaultDate.month = 0;
	_defaultDate.day = 0;
}
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
		_currentLine++;
		if (line.empty()) {
			std::cout << RED "line is empty" N << std::endl;
			continue;
		}
		try
		{
			if (_currentLine == 1 || line[0] == '#') {
				continue;
			}
			std::pair<std::string, double> csv_line = splitLine(line, ',');
			if (_currentLine == 2)
				parseAndStoreCsvLine(csv_line, _defaultDate);
			else {
				parseAndStoreCsvLine(csv_line, _db.rbegin()->first);
			}
		}
		catch(const std::exception& e)
		{
			throw std::invalid_argument(std::string(RED) + "Error: " + std::string("line [") + to_string(_currentLine) + "]: " + e.what() + std::string(N));
		}
	}
	dbFile.close();
	if (_db.empty())	throw std::invalid_argument("Error: The database file is empty.");
	std::cout << GREEN "Database loaded successfully." N << std::endl;
	// Print the database // dev
	for (std::map<Date, double>::const_iterator it = _db.begin(); it != _db.end(); ++it) {
		std::cout << "Date: " << it->first.year << "-" << std::setw(2) << std::setfill('0') << it->first.month << "-" << std::setw(2) << std::setfill('0') << it->first.day
				  << ", Value: " << std::fixed << std::setprecision(2) << it->second << std::endl;
	}
	std::cout << "Database size: " << _db.size() << std::endl;
}

std::pair<std::string, double> BitcoinExchange::splitLine(const std::string &line, char delimiter) {
	std::string	dateStr;
	std::string	valueStr;
	size_t pos = line.find(delimiter);
	if (pos == std::string::npos) {
		throw std::invalid_argument("Invalid line format.");
	}
	dateStr = line.substr(0, pos);
	valueStr = line.substr(pos + 1);
	if (dateStr.empty() || valueStr.empty()) {
		throw std::invalid_argument("Invalid line format.");
	}
	// check format of dateStr
	if (dateStr.size() != 10) {
		throw std::invalid_argument("Invalid date format.");
	}
	for (size_t i = 0; i < dateStr.size(); ++i) {
		if (i == 4 || i == 7) {
			if (dateStr[i] != '-') {
				throw std::invalid_argument("Invalid date format.");
			}
		} else if (!isdigit(dateStr[i])) {
			throw std::invalid_argument("Invalid date format.");
		}
	}
	// check format of valueStr
	int dotCount = 0;
	int numberAfterDot = 0;
	bool afterDot = false;
	
	for (size_t i = 0; i < valueStr.size(); ++i) {
		char c = valueStr[i];
		if (c == '.') {
			dotCount++;
			if (dotCount > 1) {
				throw std::invalid_argument("Invalid value format.");
			}
			afterDot = true;
		}
		else if (!isdigit(c)) {
			throw std::invalid_argument("Invalid value format.");
		}
		else if (afterDot) {
			numberAfterDot++;
			if (numberAfterDot > 2) {
				throw std::invalid_argument("Invalid value format.");
			}
		}
	}
	double value = atof(valueStr.c_str());
	return (std::make_pair(dateStr, value));
}

void BitcoinExchange::parseAndStoreCsvLine(const std::pair<std::string, double> &csv_line, const Date &previous_date) {
	std::string	dateStr = csv_line.first;
	double		value = csv_line.second;
	int			year = atoi((dateStr.substr(0, 4)).c_str());
	int			month = atoi((dateStr.substr(5, 2)).c_str());
	int			day = atoi((dateStr.substr(8, 2)).c_str());
	Date		date;
	
	checkDateValidity(year, month, day);
	date.year = year;
	date.month = month;
	date.day = day;
	if (!(previous_date.year == 0 && previous_date.month == 0 && previous_date.day == 0)) {
		if (date == previous_date) {
			throw std::invalid_argument("Invalid date: date is the same as the previous date.");
		}
		if (date < previous_date) {
			throw std::invalid_argument("Invalid date: date is earlier than the previous date.");
		}
	}
	checkValueValidity(value);
	_db[date] = value;
}

// helper

void BitcoinExchange::checkDateValidity(int year, int month, int day) {
	if (year < 1919 || year > 2025)	throw std::invalid_argument("Invalid date: year out of range.");
	if (month < 1 || month > 12)	throw std::invalid_argument("Invalid date: month out of range.");
	if (day < 1 || day > 31)	throw std::invalid_argument("Invalid date: day out of range.");
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)	throw std::invalid_argument("Invalid date: day out of range.");
	if (month == 2) {
		if (day > 29)	throw std::invalid_argument("Invalid date: day out of range.");
		if (day == 29 && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))	throw std::invalid_argument("Invalid date: day out of range.");
	}
}

void BitcoinExchange::checkValueValidity(double value) {
	if (value < 0)	throw std::invalid_argument("Invalid value: negative value.");
	if (value > 999999999.99)	throw std::invalid_argument("Invalid value: too large.");
}

std::string BitcoinExchange::to_string(int value) {
	std::ostringstream	oss;

	oss << value;
	return (oss.str());
}
