#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <stack>

// all type of containers : https://www.geeksforgeeks.org/containers-cpp-stl/

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	try {
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::deque<int> deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);
	deq.push_back(4);
	deq.push_back(5);
	try {
		std::deque<int>::iterator it = easyfind(deq, 3);
		std::cout << "Found in deque: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
