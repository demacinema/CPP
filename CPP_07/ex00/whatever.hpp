/* demrodri@student.42wolfsburg.de
   CPP07 - ex00 - whatever - whatever.hpp */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> // nomally the letter T is used for type, but any letter can be used
void swap(T& a, T& b) // pass by reference to modify the original values
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b) // pass by value to avoid modifying the original values
{
	return (a < b) ? a : b; // if a is less than b, return a, else return b
}

template <typename T>
T max(T a, T b) // pass by value to avoid modifying the original values
{
	return (a > b) ? a : b; // if a is greater than b, return a, else return b
}

#endif