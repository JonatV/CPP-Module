#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
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
		static bool	isChar(const std::string &);
		static bool	isInt(const std::string &);
		static bool	isFloat(const std::string &);
		static bool	isDouble(const std::string &);
		static int	findType(const std::string &);
		static void	displayChar(const std::string &input);
		static void	displayInteger(const std::string &input);
		static void	displayDouble(const std::string &input);
		static void	displayFloat(const std::string &input);
		static void	displayFloatDoubleException(const std::string &input);
		static bool	checkIntOverflow(const std::string &);
		static std::string	trim(const std::string &);
	public:
	// Member functions
		static void convert(const std::string &);
};

#endif
