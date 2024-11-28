#include "Sed.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 4)
		std::cout << "Wrong command call (filename string_to_replace new_string)" << std::endl;
	else
	{
		Sed strEditor(argv[2], argv[3], argv[1]);
		if (!strEditor.startReplacement())
			return (1);
		std::cout << "Modified text can be found in : \e[1;35m" << argv[1] << ".replace\e[0m " << std::endl;
	}
	return (0);
}
