#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define WHITE "\033[1;37m"
#define RED "\033[31m"

class ScalarConverter
{
	private:
		static bool	isChar(const std::string &);
		static bool	isInt(const std::string &);
		static bool	isFloat(const std::string &);
		static bool	isDouble(const std::string &);
		static int	findType(const std::string &);
	public:
	// Member functions
		static void convert(const std::string &);
};

#endif
