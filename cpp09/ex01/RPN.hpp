#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdexcept>
#include <iostream>

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
