#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN &other) {
	_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {
}

void RPN::processInput(const std::string& input) {
	for (size_t i = 0; i < input.size(); ++i) {
		char c = input[i];
		if (c >= '0' && c <= '9') {
			_stack.push(c - '0');
		} else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (_stack.size() < 2) {
				throw std::runtime_error("Insufficient values in stack");
			}
			double b = _stack.top();
			_stack.pop();
			double a = _stack.top();
			_stack.pop();
			switch (c) {
				case '+':
					_stack.push(a + b);
					break;
				case '-':
					_stack.push(a - b);
					break;
				case '*':
					_stack.push(a * b);
					break;
				case '/':
					if (b == 0) throw std::runtime_error("Division by zero");
					_stack.push(a / b);
					break;
			}
		} else if (c != ' ') {
			throw std::runtime_error("Invalid character in expression");
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("Stack should contain exactly one value at the end");
	}
	std::cout << "Result: " << _stack.top() << std::endl;
	_stack.pop();
}
