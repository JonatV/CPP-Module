#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


// Destructor
Base::~Base()
{
	std::cout << "\e[2mDestructor Base called\e[0m" << std::endl;
}

Base *generate (void)
{
	time_t	t = time(0);
	if (t % 3 == 0)
		return (new A);
	else if (t % 3 == 1)
		return (new B);
	return (new C);
}

// dynamic cast will sent a null pointer if the cast is not possible
// so a simple if statement is enough
void identify(Base* p)
{
	std::cout << "Identifying pointer:\t" << p << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << "\tIdentify as A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "\tIdentify as B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "\tIdentify as C" << std::endl;
	else
		std::cout << "\tIdentify as unknown" << std::endl;
	std::cout << std::endl;
}
// dynamic cast on a reference will throw an exception if the cast is not possible
// so a try catch block is needed to intercept the exception error
void identify(Base& p)
{
	std::cout << "Identifying reference:\t" << &p << std::endl;
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "\tIdentify as A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "\tIdentify as B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "\tIdentify as C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "\tIdentify as unknown" << std::endl;
			}
		}
	}
	std::cout << std::endl;
}
