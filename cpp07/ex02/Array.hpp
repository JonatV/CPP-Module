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
		const T			&operator[](unsigned int) const;
		unsigned int	size() const;
		void			print(std::string name) const;

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
Array<T>::Array(const Array &src)
{
	std::cout << "\e[2mCopy constructor Array called\e[0m" << std::endl;
	_size = src._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "\e[2mDestructor Array called\e[0m" << std::endl;
	delete [] _array;
}

// Assignment operator
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw wrongIndex();
	return _array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw wrongIndex();
	return _array[index];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	std::cout << "\e[2mAssignation operator Array called\e[0m" << std::endl;
	if (this != &other)
	{
		delete [] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

// methods
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
void Array<T>::print(std::string name) const
{
	for (unsigned int i = 0; i < _size; i++)
		std::cout << name << ":\t" << _array[i] << std::endl;
	std::cout << std::endl;
}

// exception
template< typename T >
const char	*Array<T>::wrongIndex::what() const throw()
{
	return ("Error: Index out of bounds");
}

#endif
