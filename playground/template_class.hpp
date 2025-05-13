#ifndef TEMPLATE_CLASS_HPP
#define TEMPLATE_CLASS_HPP
#include <iostream>

template <typename T>
class Box {
	public:
		T _value;
		Box();
		Box(T);
		void show();
};

template <typename T>
Box<T>::Box() : _value() {};

template <typename T>
Box<T>::Box(T value): _value(value) {};

template <typename T>
void Box<T>::show()
{
	std::cout << "Value\t[" << _value << "]" << std::endl;
};

/////////// PAIR

template <typename T = int, typename U>
class Pair
{
	public :
		T _first;
		U _second;
		Pair(T, U);
		void show();
};

template<typename T, typename U>
Pair<T, U>::Pair(T first, U second) : _first(first), _second(second) {};

template<typename T, typename U>
void Pair<T, U>::show()
{
	std::cout << "Pair\t[" << _first << ", " << _second << "]" << std::endl;
}

#endif
