/* demrodri@student.42wolfsburg.de
   CPP08 - ex01 - span - main.cpp */

#include "Span.hpp"
#include <vector> // for std::vector
#include <list> // for std::list
#include <cstdlib> // for std::rand, std::srand
#include <iostream>

void displaySpan(const std::string& str, const Span& span)
{
	std::cout << str << std::endl;
	std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << span.longestSpan() << std::endl;
}

void basicTest()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	displaySpan("[SUBJECT TEST]", sp);

	std::cout << "--------------------------------" << std::endl;
	Span sp2 = Span(sp);
	displaySpan("[COPY TEST]", sp2);
	std::cout << "--------------------------------" << std::endl;
}

void errorTest()
{
	std::cout << "[ERROR TEST]" << std::endl;
	Span sp = Span(50);
	
	try
	{
		sp.longestSpan(); // should throw error, as there are not enough numbers
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	sp.addNumber(0); // adding only one number, 0, to test error handling. Will add at position 0, because it's the first number.

	try
	{
		sp.longestSpan(); // should throw error, as there is only one number
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	sp.addNumber(1); // adding second number, 1, to test error handling. Will add at position 1, because it's the second number.

	std::cout << "--------------------------------" << std::endl;
	displaySpan("[0-1 TEST]", sp); // should work now, as there are two numbers

	for (int i = 2; i < 50; i++) // filling up the Span to its capacity, from 2 to 49 because 0 and 1 are already added
	{
		sp.addNumber(i);
	}
	std::cout << "--------------------------------" << std::endl;

	try
	{
		sp.addNumber(100); // should throw error, as the Span is full
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	displaySpan("[FULL SPAN RESULT]", sp);
	std::cout << "--------------------------------" << std::endl;
}

void zeroTest()
{
	Span sp = Span(2);
	
	sp.addNumber(0);
	sp.addNumber(0);
	displaySpan("[ZERO TEST]", sp);
}

void rangeTest()
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "RANGE TEST: " << std::endl;
	Span sp = Span(5);

	int a[3] = {0, 10, 200};
	sp.addRange(std::begin(a), std::end(a)); // adding range of 3 elements: 0, 10, 200
	std::cout << "--------------------------------" << std::endl;
	displaySpan("[ADDING RANGE 3]", sp);

	try
	{
		sp.addNumber(3000);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;
	displaySpan("[TRY ADDING RANGE 3 AGAIN]", sp);
	
	try
	{
		sp.addRange(std::begin(a), std::end(a)); // should throw error, as adding 3 more numbers exceeds capacity
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	int b[1] = {10000};
	try
	{
		sp.addRange(std::begin(b), std::end(b)); // should work, as adding 1 more number fits capacity
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	displaySpan("[ADDED 10000]", sp);
}

void largeTest()
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "[LARGE TEST]" << std::endl;

	// Create large dataset
	std::vector<int> numbers;
	for (int i = 0; i < 15000; ++i)
	{
		numbers.push_back(rand() % 50000); // random numbers between 0 and 49999
	}

	// Add all at once using addRange
	Span sp(15000);
	sp.addRange(numbers.begin(), numbers.end());

	std::cout << "Successfully added " << sp.getData().size() << " elements using addRange" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void demonstrateRangeFeatures()
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "[RANGE ITERATOR DEMONSTRATIONS]" << std::endl;

	// Test with different container types - C++98 style
	std::vector<int> vec;
	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);
	vec.push_back(400);
	vec.push_back(500);

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	int arr[] = {1, 2, 3, 4, 5};

	Span sp(15);

	std::cout << "Adding from vector..." << std::endl;
	sp.addRange(vec.begin(), vec.end());

	std::cout << "Adding from list..." << std::endl;
	sp.addRange(lst.begin(), lst.end());

	std::cout << "Adding from array..." << std::endl;
	sp.addRange(arr, arr + 5);

	std::cout << "Total elements: " << sp.getData().size() << std::endl; // should be 15

	displaySpan("MIXED SOURCES TEST", sp);
}

int main()
{
	srand(time(0)); // Seed for random number generation

	basicTest();
	errorTest();
	zeroTest();
	rangeTest();
	largeTest();
	demonstrateRangeFeatures();
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }