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

#define N "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define GREY "\033[90m"

#define VECTOR "vector"
#define DEQUE "deque"

class PmergeMe {
	private:
		std::vector<int>	_vector;
		std::vector<int>	_arguments;
		std::deque<int>		_deque;
		bool				_firstRun;

		void checkValidInput(const char **begin, const char **end);
		void mergeVector(const char **begin, const char **end);
		void mergeDeque(const char **begin, const char **end);
		void showStats(timespec &finish, timespec &start, const std::string &containerType) const;


		// helper
		std::string to_string(int value);
		// prevent default constructor
		PmergeMe();
	public:
		PmergeMe(const char **begin, const char **end);
		// PmergeMe(const PmergeMe &other);
		// PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
};

#endif
