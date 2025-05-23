#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

int main()
{
	std::string str = "123123.12";
	std::cout << str << std::endl;

	char *endptr;
	double to_double = strtod(str.c_str(), &endptr);
	double test = 123123.12;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "strtod: " << to_double << std::endl;
	std::cout << "literal: " << test << std::endl;

	return 0;
}
