#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <class T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &);
		~Array();
		Array			&operator=(const Array &);
		T				&operator[](unsigned int);
		unsigned int	size() const;

		class			wrongIndex : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

template <typename T>
Array<T>::Array() : _size(0) {
	std::cout << "\e[2mDefault constructor Array called\e[0m" << std::endl;
	_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "\e[2mParametrized constructor Array called\e[0m" << std::endl;
	_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_array[i] = T();
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "\e[2mDestructor Array called\e[0m" << std::endl;
	delete [] _array;
}

template< typename T >
const char	*Array<T>::wrongIndex::what() const throw()
{
	return ("Error: Index out of bounds");
}

#endif
