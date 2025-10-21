/* demrodri@student.42wolfsburg.de
   CPP08 - ex01 - span - Span.cpp */

#include "Span.hpp"

Span::Span() {}

// Exception messages
const char* Span::StoreFullException::what() const throw()
{
	return "Error: cannot add number to span -> span is full";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Error: cannot find span";
}

const char* Span::OutOfRangeException::what() const throw()
{
	return "Error: cannot add numbers to span -> out of range";
}

// Getter for assignment operator
const std::multiset<int>& Span::getData() const
{
	return _data;
}

// Member functions
void Span::addNumber(int num) // adds a number to the span
{
	if (_data.size() == _capacity)
		throw StoreFullException();
	_data.insert(num);
}

int Span::shortestSpan() const // finds the shortest span between any two numbers
// uses consecutive elements to find the smallest difference
// 1. check if there are at least two numbers in the multiset
// 2. create two iterators, one for the current element and one for the next element
// 3. create a set to store the differences between consecutive elements
// 4. loop through the multiset, calculating the difference between the current and next element
// 5. insert the difference into the set
// 6. return the smallest difference (the first element in the sorted set)
{
	if (_data.size() < 2)
		throw NoSpanException(); // not enough numbers to find a span (a span is a difference between two numbers)

	std::multiset<int>::iterator it = _data.begin(); // iterator for the current element
	std::multiset<int>::iterator next = ++_data.begin(); // iterator for the next element
	std::set<int> sub; // to store the differences between consecutive elements

	for(; next != _data.end(); ++it, ++next) // loop through the multiset, calculating differences
		sub.insert(*next - *it); // insert the difference into the set, arranged in ascending order, so we can easily get the smallest difference later
	
	return *(sub.begin()); // return the smallest difference (the first element in the sorted set)
}

int Span::longestSpan() const // finds the longest span between any two numbers
// 1. check if there are at least two numbers in the multiset
// 2. return the difference between the largest and smallest elements
// (first and last elements in the sorted multiset)
{
	if (_data.size() < 2)
		throw NoSpanException();

	return *(--_data.end()) - *(_data.begin()); // difference between the largest and smallest elements
}

// Assignment operator
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_data.clear();
		_data = other.getData();
		_capacity = other._capacity;
	}
	return *this;
}

// Copy constructor
Span::Span(const Span& other) : _capacity(other._capacity)
{
	_data.clear();
	_data = other.getData();
}

// Constructors and destructor
Span::Span(unsigned int n) : _capacity(n) {}

Span::~Span()
{
	_data.clear(); // clear the multiset, though not strictly necessary because of RAII
	// (Resource Acquisition Is Initialization principle, that states that resources are automatically
	// released when they go out of scope). So the destructor of std::multiset
	// will automatically free the memory when the Span object is destroyed. 
}