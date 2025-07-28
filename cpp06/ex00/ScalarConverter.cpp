#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

				  /////////////////////
				 // General Methods //
				/////////////////////

bool	checkIntOverflow(const std::string &input)
{
	if (input.length() > 10)
		return (true);
	long long int i = std::atoll(input.c_str());
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		return (true);
	return (false);
}

std::string trim(const std::string &input)
{
	if (input.size() == 1 && input[0] == ' ')
		return (" ");
	size_t start = input.find_first_not_of(" \t\n\v\f\r");
	size_t end = input.find_last_not_of(" \t\n\v\f\r");
	return (input.substr(start, end - start + 1));
}

bool	isChar(const std::string &input)
{
	if (input.length() != 1)
		return (false);
	if (isdigit(input[0]))
		return (false);
	return (true);
}

bool	isInt(const std::string &input)
{
	int	i;

	i = 0;
	// skip all thype of spaces
	while (input[i] == " \t\n\v\f\r"[0])
		i++;

	if (input[i] == '+' || input[i] == '-')
		i++;
	while (isdigit(input[i]))
		i++;
	if (input[i] != '\0')
		return (false);
	return (true);
}

bool	isFloat(const std::string &input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (isdigit(input[i]))
		i++;
	if (input[i] == '.')
		i++;
	else
		return (false);
	while (isdigit(input[i]))
		i++;
	if (input[i] == 'f' || input[i] == 'F')
	{
		i++;
		if (input[i] == '\0')
			return (true);
	}
	return (false);
}

bool isDouble(const std::string &input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (isdigit(input[i]))
		i++;
	if (input[i] == '.')
		i++;
	else
		return (false);
	while (isdigit(input[i]))
		i++;
	if (input[i] == '\0')
		return (true);
	return (false);
}

int		findType(const std::string &input)
{
	if (isChar(input)) return (1);
	if (isInt(input)) return (4);
	if (isFloat(input)) return (2);
	if (isDouble(input)) return (3);
	if (input == "-inff" || input == "+inff" || input == "nanf") return (5);
	if (input == "-inf" || input == "+inf" || input == "nan") return (6);
	return (0);
}

				  /////////////////////
				 // DISPLAY METHODS //
				/////////////////////

void displayInteger(const std::string &input)
{
	if (checkIntOverflow(input))
	{
		std::cout << WHITE << "char: " << IMP << std::endl;
		std::cout << WHITE << "int: " << OVER << std::endl;
		std::cout << WHITE << "float: " << IMP << std::endl;
		std::cout << WHITE << "double: " << IMP << std::endl;
		return;
	}
	int i = std::atoi(input.c_str());
	std::cout << WHITE << "char: ";
	if (i < 0 || i > 127 || !isprint(static_cast<char>(i)))
		std::cout << RED << "Non displayable" RESET << std::endl;
	else
		std::cout << MAGENTA << "'" << static_cast<char>(i) << "'" << RESET << std::endl;
	std::cout << WHITE << "int: " << MAGENTA << i << RESET << std::endl;
	std::cout << WHITE << "float: " << MAGENTA << static_cast<float>(i) << ".0f" << RESET << std::endl;
	std::cout << WHITE << "double: " << MAGENTA << static_cast<double>(i) << ".0" << RESET << std::endl;
}

void displayChar(const std::string &input)
{
	std::cout << WHITE << "char: " << MAGENTA << "'" << input << "'" << RESET << std::endl;
	std::cout << WHITE << "int: " << MAGENTA << static_cast<int>(input[0]) << RESET << std::endl;
	std::cout << WHITE << "float: " << MAGENTA << static_cast<float>(input[0]) << ".0f" << RESET << std::endl;
	std::cout << WHITE << "double: " << MAGENTA << static_cast<double>(input[0]) << ".0" << RESET << std::endl;
}

void displayFloat(const std::string &input)
{
	float f = std::strtof(input.c_str(), NULL);
	std::cout << WHITE << "char: ";
	if (f < 0 || f > 127 || !isprint(static_cast<char>(f)))
		std::cout << RED << "Non displayable" RESET << std::endl;
	else
		std::cout << MAGENTA << "'" << static_cast<char>(f) << "'" << RESET << std::endl;
	std::cout << WHITE << "int: ";
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << OVER << std::endl;
	else
		std::cout << MAGENTA << static_cast<int>(f) << RESET << std::endl;
	std::cout << WHITE << "float: " << MAGENTA << std::fixed << std::setprecision(1) << f << "f" << RESET << std::endl;
	std::cout << WHITE << "double: " << MAGENTA << std::fixed << std::setprecision(1) << static_cast<double>(f) << RESET << std::endl;
}

void displayDouble(const std::string &input)
{
	double d = std::strtod(input.c_str(), NULL);
	std::cout << WHITE << "char: ";
	if (d < 0 || d > 127 || !isprint(static_cast<char>(d)))
		std::cout << RED << "Non displayable" RESET << std::endl;
	else
		std::cout << MAGENTA << "'" << static_cast<char>(d) << "'" << RESET << std::endl;
	std::cout << WHITE << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << OVER << std::endl;
	else
		std::cout << MAGENTA << static_cast<int>(d) << RESET << std::endl;
	std::cout << WHITE << "float: " << MAGENTA << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << RESET << std::endl;
	std::cout << WHITE << "double: " << MAGENTA << std::fixed << std::setprecision(1) << d << RESET << std::endl;
}


void displayFloatDoubleException(const std::string &input)
{
	std::cout << WHITE << "char: " << IMP << std::endl;
	std::cout << WHITE << "int: " << IMP << std::endl;

	std::string floatStr, doubleStr;
	if (input == "-inff" || input == "-inf")
	{
		floatStr = "-inff";
		doubleStr = "-inf";
	}
	else if (input == "+inff" || input == "+inf")
	{
		floatStr = "+inff";
		doubleStr = "+inf";
	}
	else if (input == "nanf" || input == "nan")
	{
		floatStr = "nanf";
		doubleStr = "nan";
	}
	std::cout << WHITE << "float: " << MAGENTA << floatStr << RESET << std::endl;
	std::cout << WHITE << "double: " << MAGENTA << doubleStr << RESET << std::endl;
}

				  /////////////////////
				 //  CLASS METHODS  //
				/////////////////////

// constr / destr
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string &input)
{
	if (input.empty())
	{
		std::cout << RED << "Hop hop hop hop! Gimme something..." << RESET << std::endl;
		std::cout << "Usage: ./scalar_converter " << WHITE << "<I N P U T>" << std::endl;
		return;
	}
	if (input.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
	{
		if (input.size() == 1 && input[0] == ' ')
			std::cout << RED << "SPACE" << std::endl;
		else
		{
			std::cout << RED << "No no no (nice try)" << RESET << std::endl;
			std::cout << "Usage: ./scalar_converter " << WHITE << "<I N P U T>" << std::endl;
			return;
		}
	}
	std::string trimmed = trim(input);
	int	type = findType(trimmed);
	std::cout << WHITE << "Initial type is: ";
	switch (type)
	{
		case 1: std::cout << MAGENTA << "char" << RESET << std::endl; displayChar(trimmed); break;
		case 2: std::cout << MAGENTA << "float" << RESET << std::endl; displayFloat(trimmed); break;
		case 3: std::cout << MAGENTA << "double" << RESET << std::endl; displayDouble(trimmed); break;
		case 4: std::cout << MAGENTA << "int" << RESET << std::endl; displayInteger(trimmed); break;
		case 5: std::cout << MAGENTA << "float (exception)" << RESET << std::endl; displayFloatDoubleException(trimmed); break;
		case 6: std::cout << MAGENTA << "double (exception)" << RESET << std::endl; displayFloatDoubleException(trimmed); break;
		default: std::cout << RED << "Unknown" << RESET << std::endl; break;
	}
}
