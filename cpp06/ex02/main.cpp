#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <string>
#include <math.h>

class Baaaad: public Base{};

Base *generate (void)
{
	if (rand() % 3 == 0)
		return (new A);
	else if (rand() % 3 == 1)
		return (new B);
	return (new C);
}

// dynamic cast will send a null pointer if the cast is not possible
// so a simple if statement is enough
void identify(Base* p)
{
	if (p == NULL)
	{
		std::cout << "Pointer is null" << std::endl;
		return;
	}
	std::cout << "Pointer:\t" << p << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << "\t\tIdentify as A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "\t\tIdentify as B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "\t\tIdentify as C" << std::endl;
	else
		std::cout << "\t\tIdentify as unknown" << std::endl;
	std::cout << std::endl;
}

// dynamic cast on a reference will throw an exception if the cast is not possible
// so a try catch block is needed to intercept the exception error
void identify(Base& p)
{
	std::cout << "Reference:\t" << &p << std::endl;
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "\t\tIdentify as A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "\t\tIdentify as B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "\t\tIdentify as C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "\t\tIdentify as unknown" << std::endl;
			}
		}
	}
	std::cout << std::endl;
}

int	main(void)
{
	srand(time(0));

	Base *test1 = generate();
	Base *test2 = generate();
	Base *test3 = generate();
	Base *test4 = generate();
	Base *test5 = generate();
	Base *test6 = generate();
	
	identify(test1);
	identify(*test1);
	std::cout << "------------------------------------" << std::endl;
	identify(test2);
	identify(*test2);
	std::cout << "------------------------------------" << std::endl;
	identify(test3);
	identify(*test3);
	std::cout << "------------------------------------" << std::endl;
	identify(test4);
	identify(*test4);
	std::cout << "------------------------------------" << std::endl;
	identify(test5);
	identify(*test5);
	std::cout << "------------------------------------" << std::endl;
	identify(test6);
	identify(*test6);
	std::cout << "------------------------------------" << std::endl;

	delete test1;
	delete test2;
	delete test3;
	delete test4;
	delete test5;
	delete test6;

	Base *bad = new Baaaad;
	identify(bad);
	identify(*bad);
	delete bad;
	return 0;
}
