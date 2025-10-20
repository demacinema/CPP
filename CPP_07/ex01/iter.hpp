/* demrodri@student.42wolfsburg.de
   CPP07 - ex01 - iter - iter.hpp */

#ifndef ITER_HPP
# define ITER_HPP

// Template function that works with any array type and any function type
template<typename T, typename F>
void iter(T* array, const size_t length, F function)
{
	for (size_t i = 0; i < length; i++) {
		function(array[i]);
	}
}

#endif