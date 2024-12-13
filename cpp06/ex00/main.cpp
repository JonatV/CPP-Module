#include "ScalarConverter.hpp"

#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Usage: ./scalar_converter <input>" << std::endl;
		std::cout << "\e[2mExponent are not accepted\e[0m" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
