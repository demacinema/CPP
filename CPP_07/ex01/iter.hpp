/* demrodri@student.42wolfsburg.de
   CPP07 - ex01 - iter - iter.hpp */

#ifndef ITER_HPP
# define ITER_HPP

// Generic template that works with any callable
template<typename T, typename F>
void iter(T* array, const size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

// Specialization for function template pointers
template<typename T>
void iter(T* array, const size_t length, void (*function)(const T&))
{
	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

// Specialization for non-const function template pointers
template<typename T>
void iter(T* array, const size_t length, void (*function)(T&))
{
	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

#endif