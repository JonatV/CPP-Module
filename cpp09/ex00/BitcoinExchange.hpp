#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define N "\033[0m"

// string format to parse for the date YYYY-MM-DD (i.e. 2022-09-13) and the value will be a float (i.e. 30239.19)
// container format: std::map<Date, float>
struct Date {
	int	year;
	int	month;
	int	day;

	bool operator<(const Date &) const;
	bool operator==(const Date &) const;
	bool operator!=(const Date &other) const;
};

class BitcoinExchange {
	private:
		// error handling
		int						_currentLine;
		Date					_defaultDate;
		// member variables
		std::string				_dbFileName;
		std::map<Date, float>	_db;
		
		// member functions
		std::string						to_string(int);
		void							parseAndStoreCsvLine(const std::pair<std::string, float> &csv_line, const Date &previous_date);
		void							parseAndCalcInputLine(const std::pair<std::string, float> &input_line);
		void							checkDateValidity(int year, int month, int day);
		void							checkValueValidity(float);
		std::pair<std::string, float>	splitLineCsv(const std::string &line);
		std::pair<std::string, float>	splitLineInput(const std::string &line);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(BitcoinExchange const &src); 
		~BitcoinExchange();
		
		void dbHandler();
		void inputHandler(const std::string &inputFileName);
};

#endif
