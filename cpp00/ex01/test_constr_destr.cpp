#include <iostream>

class Test
{
	public:
		Test();
		~Test();
};

Test::Test()
{
	std::cout << "Constructor here\n";
}

Test::~Test()
{
	std::cout << "Destructor here\n";
}

int	main(void)
{
	Test myObj;

	return 0;
}
