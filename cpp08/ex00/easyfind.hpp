#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), to_find);
	if (iter == container.end())
		throw std::out_of_range("No match found");
	return (iter);
}

#endif

