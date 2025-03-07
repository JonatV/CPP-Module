#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <string>

class Baaaad: public Base{};

int	main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	Base *bad = new Baaaad;
	identify(bad);
	identify(*bad);
	return 0;
}
