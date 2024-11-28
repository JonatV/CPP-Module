#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		Harl	harl;
		harl.complain(argv[1]);
	}
	return (0);
}
