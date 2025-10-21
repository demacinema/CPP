/* demrodri@student.42wolfsburg.de
   CPP08 - ex00 - easyfind - easyfind.hpp */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm> // for std::find, which is used to search for an element in a range.
#include <stdexcept> // for std::runtime_error, which is used to throw an exception when the element is not found.

template <typename T>
typename T::iterator easyfind(T& container, int n) // function template that searches for an integer 'n' in a container 'T'
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	// std::find is a standard algorithm that searches for a value in a range
	// it takes three arguments: the beginning iterator, the ending iterator, and the value to search for.
	if (it == container.end()) // if the element is not found, throw an exception
		throw std::runtime_error("not found");
	return it;
}

#endif