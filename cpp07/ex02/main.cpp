#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"


// to test :
// 1. Default constructor
// 2. Parameterized constructor
// 3. Copy constructor
// 4. operator
//    4.1 operator=
//    4.2 operator[]
// 5. Exception handling for out-of-bounds access
// 6. Const access
// 7. Deep copy (modifying the original should not affect the copy)
// 8. Destructor
// 9. Size method
int main() {
	std::cout << CYAN << "== Test: Array default constructor ==" << RESET << std::endl;
	Array<int> arrInt;

	std::cout << CYAN << "== Test: Array creation, deep copy, and assignment ==" << RESET << std::endl;
	Array<int> arrInt2(5);
	arrInt2[0] = 42;
	arrInt2[1] = 19;
	arrInt2[2] = 1337;
	Array<int> arrInt3(arrInt2);
	arrInt2[2] = 19;
	arrInt3[3] = 100;
	arrInt2.print("\tarrInt2");
	arrInt3.print("\tarrInt3");
	std::cout << CYAN << "== Test: Array operator= and operator[] ==" << RESET << std::endl;
	arrInt = arrInt3;
	arrInt.print("\tarrInt");
	std::cout << "\taccessing arrInt[2]: " << arrInt[2] << std::endl << std::endl;
	std::cout << CYAN << "== Test: Exception handling for out-of-bounds access ==" << RESET << std::endl;
	try {
		std::cout << "\tTrying to access arrInt[10] (out of bounds):\n";
		std::cout << arrInt[1000] << std::endl;
	} catch (const Array<int>::wrongIndex &e) {
		std::cerr << RED << "\tException: " << e.what() << RESET << std::endl;
	}
	std::cout << CYAN << "== Test: Const access ==" << RESET << std::endl;
	const Array<int> constArrInt(arrInt);
	std::cout << "\tAccessing constArrInt[2]: " << constArrInt[2] << std::endl;
	std::cout << CYAN << "== Test: Size method ==" << RESET << std::endl;
	Array<int> sizeTest(10);
	std::cout << "\tSize of sizeTest: " << sizeTest.size() << std::endl;
	std::cout << CYAN << "== Test: Array of strings ==" << RESET << std::endl;
	Array<std::string> arrStr(3);
	arrStr[0] = "Hi";
	arrStr[1] = "42 Brux Brux";
	arrStr[2] = "!";
	arrStr.print("\tarrStr");

	return 0;
}
