#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iomanip>
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"

#define IMP "\033[1;31mimpossible\033[0m"
#define OVER "\033[1;31moverflow\033[0m"

// info	: Having the destructor and destructor in private prevent the user
// 		  to be able to instantiate the class.
// Other way : Creating a pure virtual could define the class abstract thus not instantiable
// Not orthodox since it is not possible to instantiate thus no copy is possible.
class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
	// Member functions
		static void convert(const std::string &);
};

#endif
