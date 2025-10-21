/* demrodri@student.42wolfsburg.de
   CPP08 - ex01 - span - Span.hpp */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <set> // for std::multiset, std::set, std::map, std::multimap
#include <exception> // for std::exception

class Span
{
	private:
		std::multiset<int> _data; // to store numbers in sorted order, allowing duplicates
		unsigned int _capacity;
		Span();
		
	public:
		class StoreFullException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoSpanException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class OutOfRangeException: public std::exception
		{
			public:
				const char* what() const throw();
		};

	const std::multiset<int>& getData() const; // for assignment operator, it returns the data of another Span. Using multiset to keep numbers sorted.

	void addNumber(int num); // adds a number to the span
	int shortestSpan() const; // finds the shortest span between any two numbers
	int longestSpan() const; // finds the longest span between any two numbers

	template <typename T>
	void addRange(T begin, T end) // adds a range of numbers to the span
	{
		if (static_cast<unsigned int>(std::distance(begin, end)) > (_capacity - _data.size())) // check if range fits
			throw OutOfRangeException();
//---->>>
		for (; begin != end; ++begin)
			addNumber(*begin);
	}

	Span& operator=(const Span& other);
	Span(unsigned int n);
	Span(const Span& other);
	~Span();
};

#endif





//----->>>
// Using for loop to add each number in the range, (; because begin is an iterator, not an index)
// the syntax for (; begin != end; ++begin) can be translated as:
// for (initialization; condition; increment)
// initialization: (nothing to initialize here, we need to use the value of begin as it is)
// condition: continue the loop as long as begin is not equal to end
// increment: move the iterator to the next element in the range