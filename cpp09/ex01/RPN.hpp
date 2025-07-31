#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdexcept>
#include <iostream>

// container format: std::stack<double>
// why? Because Mister Łukasiewicz based the RPN on a stack structure! (LIFO)

class RPN {
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void processInput(const std::string& input);
	private:
		std::stack<double> _stack;
};

#endif
