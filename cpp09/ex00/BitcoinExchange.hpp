#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define N "\033[0m"

// string format to parse for the date YYYY-MM-DD (i.e. 2022-09-13) and the value will be a double (i.e. 30239.19)

struct Date {
	int	year;
	int	month;
	int	day;

	bool operator<(const Date &) const;
};

class BitcoinExchange {
	private:
		std::string				_dbFileName;
		std::map<Date, double>	_db;
	public:
		BitcoinExchange();
		// BitcoinExchange(const BitcoinExchange &copy);
		// BitcoinExchange &operator=(BitcoinExchange const &src); 
		~BitcoinExchange();

		void dbHandler();
		std::pair<std::string, double> splitLine(const std::string &line, char delimiter = ',');
};

#endif
