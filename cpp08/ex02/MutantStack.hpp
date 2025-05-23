#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

// Stack store its data in a protected container C, its by default a double edge queue (deque)

template <typename T>
class MutantStack : public std::stack<T> {
	public:
	typedef typename std::stack<T>::container_type::iterator					iterator;
	typedef typename std::stack<T>::container_type::const_iterator				const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator			reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	MutantStack();
	MutantStack(const MutantStack<T> &copy);
	MutantStack<T> &operator=(MutantStack<T> const &src);
	~MutantStack();

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	std::cout << "\e[0;32mMutantStack default constructor called\e[0m" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy) {
	std::cout << "\e[0;32mMutantStack copy constructor called\e[0m" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &src) {
	std::cout << "\e[0;32mMutantStack copy assignment operator called\e[0m" << std::endl;
	if (this != &src)
		std::stack<T>::operator=(src);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "\e[0;32mMutantStack destructor called\e[0m" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return this->c.rend();
}
#endif
