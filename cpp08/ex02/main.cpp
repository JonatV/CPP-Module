#include "MutantStack.hpp"

// int main(void)
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	++ite;
// 	--ite;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

#include <list>

int main() {
	std::cout << "=== Testing Default Constructor ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(10);
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(100);
	mstack.push(1000);
	mstack.push(10000);
	mstack.push(100000);

	std::cout << "\n=== Testing Iterators ===" << std::endl;
	std::cout << "Iterating through stack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << "Reverse iterating through stack:" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << std::endl;
	}

	const MutantStack<int> constMstack = mstack;
	std::cout << "Const iterating through stack:" << std::endl;
	for (MutantStack<int>::const_iterator cit = constMstack.begin(); cit != constMstack.end(); ++cit) {
		std::cout << *cit << std::endl;
	}

	std::cout << "Const reverse iterating through stack:" << std::endl;
	for (MutantStack<int>::const_reverse_iterator crit = constMstack.rbegin(); crit != constMstack.rend(); ++crit) {
		std::cout << *crit << std::endl;
	}

	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	MutantStack<int> copyStack(mstack);
	std::cout << "Copied stack:" << std::endl;
	for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	MutantStack<int> assignedStack;
	assignedStack = mstack;
	std::cout << "Assigned stack:" << std::endl;
	for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << "\n=== Testing with Different Data Types ===" << std::endl;
	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("World");
	stringStack.push("MutantStack");
	std::cout << "String stack:" << std::endl;
	for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
		std::cout << *it << std::endl;
	}
	return 0;
}
