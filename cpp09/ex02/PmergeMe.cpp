#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const char **begin, const char **end) : _firstRun(true){
	// Start by checking if the input is valid
	// only integers are allowed
	// no negative numbers
	// no duplicates
	// no empty input
	// no non-numeric characters
	// check for "1 2 3" and check for 1 2 3 -> one is a string with all numbers, the other is a list of argv
	try {
		checkValidInput(begin, end);
	}
	catch (const std::invalid_argument &e) {
		std::cerr << RED << "Error: " << e.what() << N << std::endl;
		exit(EXIT_FAILURE);
	}
	catch (const std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << N << std::endl;
		exit(EXIT_FAILURE);
	}
	// start chrono
	struct timespec start, finish;
	clock_gettime(CLOCK_MONOTONIC, &start);
	// run merge
	mergeVector(begin, end);
	// stop chrono
	clock_gettime(CLOCK_MONOTONIC, &finish);
	// print results
	showStats(finish, start, VECTOR);
	std::cout << std::endl;
	// start chrono
	clock_gettime(CLOCK_MONOTONIC, &start);
	// run merge
	mergeDeque(begin, end);
	// stop chrono
	clock_gettime(CLOCK_MONOTONIC, &finish);
	// print results
	showStats(finish, start, DEQUE);
}

void PmergeMe::showStats(timespec &finish, timespec &start, const std::string &containerType) const
{
	long seconds = finish.tv_sec - start.tv_sec;
	long nanoseconds = finish.tv_nsec - start.tv_nsec;
	double microseconds = seconds * 1e6 + nanoseconds / 1e3;

	std::cout << std::fixed;
	std::cout.precision(5); // 5 digits after the decimal point
	std::cout << "Time taken for " << containerType << " merge: " << microseconds << " us" << std::endl;
}

void PmergeMe::mergeVector(const char **begin, const char **end)
{
	//Initialize vector
	if (_firstRun) {
		std::cout << GREY << "First run, initializing vector" << N << std::endl;
	} else {
		std::cout << GREY << "Subsequent run, merging vector" << N << std::endl;
	}
	if (_firstRun) {
		_firstRun = false;
		for (const char **it = begin; it != end; ++it)
			_vector.push_back(std::atoi(*it));
	}
	// fordjohnson
}

void PmergeMe::mergeDeque(const char **begin, const char **end)
{
	//Initialize deque
	if (_firstRun) {
		std::cout << GREY << "First run, initializing deque" << N << std::endl;
	} else {
		std::cout << GREY << "Subsequent run, merging deque" << N << std::endl;
	}
	if (_firstRun) {
		_firstRun = false;
		for (const char **it = begin; it != end; ++it)
			_deque.push_back(std::atoi(*it));
	}
	// fordjohnson
}

PmergeMe::~PmergeMe() {
	std::cout << GREY << "Destructor called" << N << std::endl;
}

void PmergeMe::checkValidInput(const char **begin, const char **end) {
	if (begin == end) {
		throw std::invalid_argument("No input provided");
	}
	for (const char **it = begin; it != end; ++it) {
		std::string arg(*it);
		std::istringstream iss(arg);
		std::string token;
		if (arg.empty()) {
			throw std::invalid_argument("Empty input found");
		}
		while (iss >> token) {
			std::cout << "Checking token: " << token << std::endl;
			if (token[0] == '-') {
				throw std::invalid_argument("Negative numbers are not allowed: " + token);
			}
			if (token[0] == '+' && token.length() > 1) {
				token.erase(0, 1); // Remove leading '+'
			} else if (token[0] == '+') {
				throw std::invalid_argument("Invalid input: " + token);
			}
			for (size_t i = 0; i < token.length(); ++i) {
				if (!std::isdigit(token[i])) {
					throw std::invalid_argument("Non-numeric character found: " + token);
				}
			}
			int num = std::atoi(token.c_str());
			if (std::find(_arguments.begin(), _arguments.end(), num) != _arguments.end()) {
				throw std::invalid_argument("Duplicate number found: " + to_string(num));
			}
			_arguments.push_back(num);
		}
	}
	if (_arguments.empty()) {
		throw std::invalid_argument("No valid integers found in input");
	}
	// print the arguments //dev
	std::cout << "Valid input: ";
	for (std::vector<int>::const_iterator it = _arguments.begin(); it != _arguments.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


// helper function
std::string PmergeMe::to_string(int value) {
	std::ostringstream	oss;

	oss << value;
	return (oss.str());
}
