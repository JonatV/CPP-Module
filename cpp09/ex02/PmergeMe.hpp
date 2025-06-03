#ifndef PMERGEME_HPP
#define PMERGEME_HPP

// container format: std::vector<int> and std::deque<int>

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/types.h>
#include <sys/wait.h>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <climits>

#define N "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define GREY "\033[90m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#define VECTOR "vector"
#define DEQUE "deque"

class PmergeMe {
	private:
		std::vector<int>	_vector;
		std::vector<int>	_arguments;
		std::deque<int>		_deque;

		void checkValidInput(const char **begin, const char **end);
		void initVector();
		void initDeque();
		void mergeVector(std::vector<int> &vec);
		void mergeDeque(std::deque<int> &deq);
		void showStats(timespec &finishDeque, timespec &startDeque, timespec &finishVec, timespec &startVec) const;
		// helper
		std::string to_string(int value);
		// prevent default constructor
		PmergeMe();
	public:
		PmergeMe(const char **begin, const char **end);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
};

template <typename Iterator>
bool checkSorting(Iterator first, Iterator last) {
	if (first == last)
		return true;
	Iterator next = first;
	++next;
	while (next != last) {
		if (*first > *next)
			return false;
		++first;
		++next;
	}
	return true;
}
#endif
