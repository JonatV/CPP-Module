#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	Harl harl;

	harl.complain("debug");
	std::cout << std::endl;
	harl.complain("info");
	std::cout << std::endl;
	harl.complain("warning");
	std::cout << std::endl;
	harl.complain("error");
	std::cout << std::endl;
	harl.complain("nope");
	return (0);
}
