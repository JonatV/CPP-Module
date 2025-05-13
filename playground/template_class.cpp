#include "template_class.hpp"
#include <string>

int main()
{
	Box<int> bint(10);
	Box<std::string> bstring;
	Box<std::string> bstring2("the grid");
	Box<float> bfloat(4.2f);
	bint.show();
	bstring.show();
	bstring2.show();
	bfloat.show();

	Pair<int, std::string> pair1(1234, "Jonathan");
	pair1.show();
	return 0;
}
