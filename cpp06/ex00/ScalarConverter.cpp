#include "ScalarConverter.hpp"

#include <iostream>


// Member functions

bool	ScalarConverter::isChar(const std::string &input)
{
	if (input.length() != 1)
		return (false);
	if (input[0] >= 48 && input[0] <= 57)
		return (false);
	return (true);
}

bool	ScalarConverter::isInt(const std::string &input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i] >= 48 && input[i] <= 57)
		i++;
	if (input[i] == '\0')
		return (true);
	return (false);
}

bool	ScalarConverter::isFloat(const std::string &input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i] >= 48 && input[i] <= 57)
		i++;
	if (input[i] == '.')
		i++;
	else
		return (false);
	while (input[i] >= 48 && input[i] <= 57)
		i++;
	if (input[i] == 'f')
	{
		i++;
		if (input[i] == '\0')
			return (true);
	}
	return (false);
}

bool ScalarConverter::isDouble(const std::string &input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i] >= 48 && input[i] <= 57)
		i++;
	if (input[i] == '.')
		i++;
	else
		return (false);
	while (input[i] >= 48 && input[i] <= 57)
		i++;
	if (input[i] == '\0')
		return (true);
	return (false);
}

int		ScalarConverter::findType(const std::string &input)
{
	if (isChar(input))
		return (1);
	else if (isInt(input))
		return (2);
	else if (isFloat(input))
		return (3);
	else if (isDouble(input))
		return (4);
	return (0);
}

void	ScalarConverter::convert(const std::string &input)
{
	int	type;

	type = findType(input);
	std::cout << WHITE << "Type is: ";
	switch (type)
	{
		case 1:
			std::cout << MAGENTA << "char" << RESET << std::endl;
			break;
		case 2:
			std::cout << MAGENTA << "int" << RESET << std::endl;
			break;
		case 3:
			std::cout << MAGENTA << "float" << RESET << std::endl;
			break;
		case 4:
			std::cout << MAGENTA << "double" << RESET << std::endl;
			break;
		default: // 0
			std::cout << RED << "Unknown type" << RESET << std::endl;
			break;
	}
}
