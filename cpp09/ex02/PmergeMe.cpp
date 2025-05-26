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
		std::cerr << "Error: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	//fork to run both vector and deque
	pid_t pid = fork();
	if (pid < 0)
	{
		std::cerr << "Fork failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		// Child process: handle vector
		std::cout << BLUE << "Child process handling vector" << N << std::endl;
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
	}
	else
	{
		// Parent process: handle deque
		std::cout << PURPLE << "Parent process handling deque" << N << std::endl;
		// start chrono
		struct timespec start, finish;
		clock_gettime(CLOCK_MONOTONIC, &start);
		// run merge
		mergeDeque(begin, end);
		// stop chrono
		clock_gettime(CLOCK_MONOTONIC, &finish);
		// print results
		showStats(finish, start, DEQUE);

		// Wait for child process to finish
		int	status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status)) {
			std::cout << "Child process exited with status " << WEXITSTATUS(status) << std::endl;
		}
	}
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
	for (const char **it = begin; it != end; ++it)
	{
		_vector.push_back(std::atoi(*it));
	}
	// fordjohnson
}

void PmergeMe::mergeDeque(const char **begin, const char **end)
{
	//Initialize deque
	for (const char **it = begin; it != end; ++it)
	{
		_deque.push_back(std::atoi(*it));
	}
	// fordjohnson
}

PmergeMe::~PmergeMe() {
	std::cout << GREY << "Destructor called" << N << std::endl;
}

void PmergeMe::checkValidInput(const char **begin, const char **end) const {
	if (begin == end) {
		throw std::invalid_argument("No input provided");
	}
	for (const char **it = begin; it != end; ++it) {
		std::string arg(*it);
		size_t i = 0;
		
		if (arg.empty()) {
			throw std::invalid_argument("Empty input found");
		}
		while (i < arg.length())
		{
			// Check for leading spaces
			while (i < arg.length() && std::isspace(arg[i]))
				i++;
			if (i >= arg.length()) {
				throw std::invalid_argument("Empty input found");
			}
			if (arg[i] == '-') {
				throw std::invalid_argument("Negative numbers are not allowed");
			}
			// advance till non-digit character
			while (std::isdigit(arg[i])) i++;
			// Check if we reached the end of the string or a space, if not that means we have a non-numeric character
			if (i < arg.length() && !std::isspace(arg[i])) {
				throw std::invalid_argument("Non-numeric character found: " + std::string(1, arg[i]));
			}
		}
	}
}

