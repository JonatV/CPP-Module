#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

// Date operator overloads

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

bool Date::operator!=(const Date &other) const {
	return !(*this == other);
}

// BitcoinExchange cannonical form

BitcoinExchange::BitcoinExchange() : _currentLine(0), _dbFileName("data.csv"){
	_defaultDate.year = 0;
	_defaultDate.month = 0;
	_defaultDate.day = 0;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
	if (this != &src) {
		_currentLine = src._currentLine;
		_defaultDate = src._defaultDate;
		_dbFileName = src._dbFileName;
		_db = src._db;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

// BitcoinExchange methods

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
			std::pair<std::string, float> csv_line = splitLineCsv(line);
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
	_currentLine = 0;
	if (_db.empty())	throw std::invalid_argument("Error: The database file is empty.");
	std::cout << GREEN "Database loaded successfully." N << std::endl;
}

std::pair<std::string, float> BitcoinExchange::splitLineCsv(const std::string &line) {
	std::string	dateStr;
	std::string	valueStr;
	size_t pos = line.find(',');
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
	float value = atof(valueStr.c_str());
	return (std::make_pair(dateStr, value));
}

void BitcoinExchange::parseAndStoreCsvLine(const std::pair<std::string, float> &csv_line, const Date &previous_date) {
	std::string	dateStr = csv_line.first;
	float		value = csv_line.second;
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

// input handling
void BitcoinExchange::inputHandler(const std::string &inputFileName) {
	std::ifstream inputFileStream(inputFileName.c_str());
	if (!inputFileStream.is_open()) {
		throw std::ifstream::failure("Error: Could not open the input file");
	}
	if (inputFileStream.peek() == EOF) {
		throw std::ifstream::failure("Error: The input file is empty");
	}
	std::string line;
	bool isError = false;
	while (std::getline(inputFileStream, line)) {
		_currentLine++;
		if (line.empty()) {
			std::cout << YELLOW "Line is empty, skipping." N << std::endl;
			continue;
		}
		if (line[0] == '#' || _currentLine == 1) {
			warnUserFirstLineSkip(line);
			continue;
		}
		try {
			std::pair<std::string, float> input_line = splitLineInput(line);
			parseAndCalcInputLine(input_line);
		}
		catch (const std::exception &e) {
			std::cerr << RED "Error: line [" << _currentLine << "] " << e.what() << N << std::endl;
			isError = true;
			continue;
		}
	}
	inputFileStream.close();
	if (_currentLine == 1) {
		throw std::invalid_argument("Error: The input file is empty or contains only comments.");
	}
	if (isError) {
		std::cerr << RED "Some lines in the input file were not processed due to errors." N << std::endl;
	} else {
		std::cout << GREEN "All lines in the input file were processed successfully." N << std::endl;
	}
	_currentLine = 0; // Reset line counter after processing input file
}

std::pair<std::string, float> BitcoinExchange::splitLineInput(const std::string &line) {
	std::string	dateStr;
	std::string	valueStr;
	size_t pos = line.find('|');
	if (pos == std::string::npos)
		throw std::invalid_argument("Bad input => " + line);
	dateStr = line.substr(0, pos);
	valueStr = line.substr(pos + 1);
	if (dateStr.empty() || valueStr.empty())
		throw std::invalid_argument("Bad input => " + line);
	// check format of dateStr
	if (dateStr.size() != 11)
		throw std::invalid_argument("Expected date format: [YYYY-MM-DD ]");
	for (size_t i = 0; i < dateStr.size(); ++i) {
		if (i == 4 || i == 7) {
			if (dateStr[i] != '-')
				throw std::invalid_argument("Expected date format: [YYYY-MM-DD ]");
		} else if (i == 10) {
			if (dateStr[i] != ' ')
				throw std::invalid_argument("Date should end with a space.");
		}
		else if (!isdigit(dateStr[i]))
			throw std::invalid_argument("Found non-digit character in date.");
	}
	// check format of valueStr
	int dotCount = 0;
	int numberAfterDot = 0;
	bool afterDot = false;
	for (size_t i = 0; i < valueStr.size(); ++i) {
		char c = valueStr[i];
		if (i == 0){
			if (c != ' ')
				throw std::invalid_argument("Value should start with a space.");
		}
		else if (i == 1 && c == '-') {
				throw std::invalid_argument("Not a positive number.");
		}
		else if (i > 1 && c == '.') {
			dotCount++;
			if (dotCount > 1)
				throw std::invalid_argument("Too many dots in value.");
			afterDot = true;
		}
		else if (!isdigit(c))
			throw std::invalid_argument("Not a number.");
		else if (afterDot) {
			numberAfterDot++;
			if (numberAfterDot > 2)
				throw std::invalid_argument("Too many digits after dot.");
		}
	}
	float value = atof(valueStr.c_str()); 
	if (value >= 1000)
		throw std::invalid_argument("Value too large.");
	if (value == 0)
		throw std::invalid_argument("Value too small.");
	return (std::make_pair(dateStr, value));
}

void BitcoinExchange::parseAndCalcInputLine(const std::pair<std::string, float> &input_line) {
	std::string	dateStr = input_line.first;
	float		value = input_line.second;
	int			year = atoi((dateStr.substr(0, 4)).c_str());
	int			month = atoi((dateStr.substr(5, 2)).c_str());
	int			day = atoi((dateStr.substr(8, 2)).c_str());
	Date		date;

	checkDateValidity(year, month, day);
	date.year = year;
	date.month = month;
	date.day = day;
	
	if (_db.empty()) {
		throw std::invalid_argument("Database is empty.");
	}
	std::map<Date, float>::iterator it = _db.lower_bound(date);
	if (it == _db.end()) {
		it = --_db.end();
	}
	if (it->first != date) {
		if (it == _db.begin()) {
			throw std::invalid_argument("No data available for the given date.");
		}
		--it;
	}
	float rate = it->second;
	float result = value * rate;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << dateStr << " => " << value << " = " << result << std::endl;
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

void BitcoinExchange::checkValueValidity(float value) {
	if (value < 0)	throw std::invalid_argument("Invalid value: negative value.");
	if (value > 999999999.99)	throw std::invalid_argument("Invalid value: too large.");
}

std::string BitcoinExchange::to_string(int value) {
	std::ostringstream	oss;

	oss << value;
	return (oss.str());
}

void BitcoinExchange::warnUserFirstLineSkip(const std::string &line) {
	if (_currentLine == 1) {
		std::string expectation = "date | value";
		if (line != expectation)
			std::cout << YELLOW "Warning: The first line is meant to be the header. Found: [" << line << "], it will be skipped." N << std::endl;
	}
}
