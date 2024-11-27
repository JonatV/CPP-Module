#include <fstream>
#include <iostream>
#include <string>

int	main ()
{
	std::string	buffer;

	std::ifstream myFile("file.log");
	while(getline(myFile, buffer))
		std::cout << buffer;
	myFile.close();
}
