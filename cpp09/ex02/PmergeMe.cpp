#include "PmergeMe.hpp"

// ┌──────────────────────────────────────────────┐
// │                CLASS BASIC's                 │
// └──────────────────────────────────────────────┘

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		std::cout << GREY << "Assignment operator called" << N << std::endl;
		_vector = other._vector;
		_arguments = other._arguments;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	std::cout << GREY << "Copy constructor called" << N << std::endl;
	*this = other;  // use assignment operator
}

PmergeMe::~PmergeMe() {
	std::cout << GREY << "Destructor called" << N << std::endl;
}

PmergeMe::PmergeMe(const char **begin, const char **end) {
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
	struct timespec startVec, finishVec;
	// start chrono
	clock_gettime(CLOCK_MONOTONIC, &startVec);
	// init vector
	initVector();
	// run merge
	mergeVector(_vector);
	// stop chrono
	clock_gettime(CLOCK_MONOTONIC, &finishVec);

	// DEQUE
	struct timespec startDeque, finishDeque;
	// start chrono
	clock_gettime(CLOCK_MONOTONIC, &startDeque);
	// init deque
	initDeque();
	// run merge
	mergeDeque(_deque);
	// stop chrono
	clock_gettime(CLOCK_MONOTONIC, &finishDeque);

	// print results
	showStats(finishDeque, startDeque, finishVec, startVec);
}

// ┌──────────────────────────────────────────────┐
// │                PROCESS VECTOR                │
// └──────────────────────────────────────────────┘


void PmergeMe::initVector()
{
	for (std::vector<int>::const_iterator it = _arguments.begin(); it != _arguments.end(); ++it)
		_vector.push_back(*it);
}

void PmergeMe::mergeVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

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
	mergeVector(large);
	std::vector<int> merged = large;
	std::vector<int>::iterator smallIt = small.begin();
	while(smallIt != small.end()) {
		std::vector<int>::iterator pos = std::lower_bound(merged.begin(), merged.end(), *smallIt);
		merged.insert(pos, *smallIt);
		++smallIt;
	}
	vec = merged;
}

// ┌──────────────────────────────────────────────┐
// │                PROCESS DEQUE                 │
// └──────────────────────────────────────────────┘

void PmergeMe::initDeque()
{
	for (std::vector<int>::const_iterator it = _arguments.begin(); it != _arguments.end(); ++it)
		_deque.push_back(*it);
}

void PmergeMe::mergeDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<int> small;
	std::deque<int> large;
	std::deque<int>::iterator it = deq.begin();
	while (it != deq.end()) {
		int	first = *it++;
		if (it == deq.end()) {
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
	mergeDeque(large);
	std::deque<int> merged = large;
	std::deque<int>::iterator smallIt = small.begin();
	while(smallIt != small.end()) {
		std::deque<int>::iterator pos = std::lower_bound(merged.begin(), merged.end(), *smallIt);
		merged.insert(pos, *smallIt);
		++smallIt;
	}
	deq = merged;
}

// ┌──────────────────────────────────────────────┐
// │                    HELPER                    │
// └──────────────────────────────────────────────┘

std::string PmergeMe::to_string(int value) {
	std::ostringstream	oss;

	oss << value;
	return (oss.str());
}

void PmergeMe::showStats(timespec &finishDeque, timespec &startDeque, timespec &finishVec, timespec &startVec) const
{
	long secondsDeque = finishDeque.tv_sec - startDeque.tv_sec;
	long nanosecondsDeque = finishDeque.tv_nsec - startDeque.tv_nsec;
	double microsecondsDeque = secondsDeque * 1e6 + nanosecondsDeque / 1e3;

	long secondsVec = finishVec.tv_sec - startVec.tv_sec;
	long nanosecondsVec = finishVec.tv_nsec - startVec.tv_nsec;
	double microsecondsVec = secondsVec * 1e6 + nanosecondsVec / 1e3;

	std::cout << PURPLE << "Before: ";
	for (std::vector<int>::const_iterator it = _arguments.begin(); it != _arguments.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << N << std::endl;
	std::cout << PURPLE << "After: ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << N << std::endl;
	std::cout << std::fixed;
	std::cout.precision(5);
	std::cout << BLUE << "Time to process a range of " << _arguments.size() << " elements with " << YELLOW << "std::vector:\t" << BLUE << microsecondsVec << " us" << N << std::endl;
	std::cout << BLUE << "Time to process a range of " << _arguments.size() << " elements with " << YELLOW << "std::deque:\t" << BLUE << microsecondsDeque << " us" << N << std::endl;
	if (!checkSorting(_vector.begin(), _vector.end())) {
		std::cerr << RED << "Error: vector is not sorted" << N << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!checkSorting(_deque.begin(), _deque.end())) {
		std::cerr << RED << "Error: deque is not sorted" << N << std::endl;
		exit(EXIT_FAILURE);
	}
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
			if (token[0] == '-') {
				throw std::invalid_argument("Negative numbers are not allowed: " + token);
			}
			if (token[0] == '+' && token.length() > 1) {
				token.erase(0, 1);
			} else if (token[0] == '+') {
				throw std::invalid_argument("Invalid input: " + token);
			}
			for (size_t i = 0; i < token.length(); ++i) {
				if (!std::isdigit(token[i])) {
					throw std::invalid_argument("Non-numeric character found: " + token);
				}
			}
			if (token.length() > 10) {
				throw std::invalid_argument("Number too large for an int: " + token);
			}
			long long num_ll = std::atoll(token.c_str());
			if (num_ll > INT_MAX) {
				throw std::invalid_argument("Number too large for an int: " + token);
			}
			int num = static_cast<int>(num_ll);
			if (std::find(_arguments.begin(), _arguments.end(), num) != _arguments.end()) {
				throw std::invalid_argument("Duplicate number found: " + to_string(num));
			}
			_arguments.push_back(num);
		}
	}
	if (_arguments.empty()) {
		throw std::invalid_argument("No valid integers found in input");
	}
}
