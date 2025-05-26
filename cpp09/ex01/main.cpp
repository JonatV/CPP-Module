#include "RPN.hpp"
#define RED "\033[31m"
#define N "\033[0m"
int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <expression>(e.g., \"3 4 + 2 *\")" << std::endl;
		return 1;
	}
	RPN rpn;
	try {
		rpn.processInput(argv[1]);
 	} catch (const std::runtime_error &e) {
		std::cerr << RED "Error: " << e.what() << N << std::endl;
		return 1;
	}
	return 0;
}
