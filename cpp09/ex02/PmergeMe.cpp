#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const char **begin, const char **end) {
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
	// VECTOR
	// start chrono
	struct timespec start, finish;
	clock_gettime(CLOCK_MONOTONIC, &start);
	// init vector
	initVector();
	// run merge
	mergeVector(_vector);
	// stop chrono
	clock_gettime(CLOCK_MONOTONIC, &finish);
	// print results
	showStats(finish, start, VECTOR);
	std::cout << std::endl;

	struct timespec startDeque, finishDeque;
	// DEQUE
	// start chrono
	clock_gettime(CLOCK_MONOTONIC, &startDeque);
	// init deque
	initDeque();
	// run merge
	mergeDeque(_deque);
	// stop chrono
	clock_gettime(CLOCK_MONOTONIC, &finishDeque);
	// print results
	showStats(finishDeque, startDeque, DEQUE);
}

void PmergeMe::showStats(timespec &finish, timespec &start, const std::string &containerType) const
{
	long seconds = finish.tv_sec - start.tv_sec;
	long nanoseconds = finish.tv_nsec - start.tv_nsec;
	double microseconds = seconds * 1e6 + nanoseconds / 1e3;

	std::cout << std::fixed;
	std::cout.precision(5); // 5 digits after the decimal point
	std::cout << "Time taken for " << containerType << " merge: " << microseconds << " us" << std::endl;
	if (containerType == VECTOR) {
		std::cout << "Sorted vector: ";
		for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	} else if (containerType == DEQUE) {
		std::cout << "Sorted deque: ";
		for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

void PmergeMe::initVector()
{
	for (std::vector<int>::const_iterator it = _arguments.begin(); it != _arguments.end(); ++it)
		_vector.push_back(*it);
}

void PmergeMe::mergeVector(std::vector<int> &vec)
{
	// fordjohnson (merge insert)
	//todo check for <= 1 element in vector
	if (vec.size() <= 1) {
		std::cout << "Vector is already sorted or has only one element." << std::endl;
		return;
	}
	// print vector
	std::cout << "Merging vector: ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::vector<int> small;
	std::vector<int> large;
	std::vector<int>::iterator it = vec.begin();
	while (it != vec.end()) {
		int	first = *it++;
		if (it == vec.end()) {
			small.push_back(first);
			break;
		}
		int	second = *it++;

		if (first < second) {
			small.push_back(first);
			large.push_back(second);
		} else {
			small.push_back(second);
			large.push_back(first);
		}
	}
	std::cout << BLUE << "Small vector: ";
	for (std::vector<int>::const_iterator it = small.begin(); it != small.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << N << std::endl;
	std::cout << PURPLE << "Large vector: ";
	for (std::vector<int>::const_iterator it = large.begin(); it != large.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << N << std::endl;
	mergeVector(large);
	std::vector<int> merged = large;
	std::vector<int>::iterator smallIt = small.begin();
	while(smallIt != small.end()) {
		std::vector<int>::iterator pos = std::lower_bound(merged.begin(), merged.end(), *smallIt);
		merged.insert(pos, *smallIt);
		++smallIt;
	}
	std::cout << "Merged vector: ";
	for (std::vector<int>::const_iterator it = merged.begin(); it != merged.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	vec = merged;
}

void PmergeMe::initDeque()
{
	for (std::vector<int>::const_iterator it = _arguments.begin(); it != _arguments.end(); ++it)
		_deque.push_back(*it);
}

void PmergeMe::mergeDeque(std::deque<int> &deq)
{
	// fordjohnson
	(void)deq;
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
