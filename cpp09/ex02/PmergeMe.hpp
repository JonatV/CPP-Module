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
#include <iomanip>

#define N "\033[0m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define GREY "\033[90m"

#define VECTOR "vector"
#define DEQUE "deque"

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		void checkValidInput(const char **begin, const char **end) const;
		void mergeVector(const char **begin, const char **end);
		void mergeDeque(const char **begin, const char **end);
		void showStats(timespec &finish, timespec &start, const std::string &containerType) const;
		PmergeMe();
	public:
		PmergeMe(const char **begin, const char **end);
		// PmergeMe(const PmergeMe &other);
		// PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
};

#endif
