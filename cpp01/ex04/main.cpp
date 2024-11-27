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
		{
			std::cerr << "Error during replacement" << std::endl;
			return (1);
		}
		std::cout << "You can find the new file at " << argv[1] << ".replace" << std::endl;
	}
	return (0);
}
