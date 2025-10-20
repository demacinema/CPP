/* demrodri@student.42wolfsburg.de
   CPP07 - ex01 - iter - main.cpp */

#include <iostream>
#include <string>
#include "iter.hpp"

// Function templates that can work with any type

// 1. Const reference - for read-only operations
template<typename T>
void printElement(const T& element)
{
	std::cout << element << " ";
}

// 2. Non-const reference - for modifying operations
template<typename T>
void doubleElement(T& element)
{
	element = element + element;  // Works for numbers and strings
}

template<typename T>
void incrementElement(T& element)
{
	element++;  // Works for numbers and characters
}

// 3. Regular functions (non-template)
void printInt(const int& n)
{
	std::cout << "[" << n << "] ";
}

void makeUppercase(char& c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
}

// Test function to display arrays
template<typename T>
void displayArray(T* array, size_t size, const std::string& title)
{
	std::cout << title << ": ";
	for (size_t i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "=== ITER FUNCTION TEMPLATE TESTS ===" << std::endl;
	
	// Test 1: Integer array with const function
	std::cout << "\n--- Test 1: Integer array with const function ---" << std::endl;
	int integers[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(integers) / sizeof(integers[0]);
	
	displayArray(integers, intSize, "Original integers");
	std::cout << "Using printElement: ";
	iter(integers, intSize, printElement<int>);
	std::cout << std::endl;
	
	std::cout << "Using printInt: ";
	iter(integers, intSize, printInt);
	std::cout << std::endl;

	// Test 2: Integer array with non-const function (modifying)
	std::cout << "\n--- Test 2: Integer array with modifying function ---" << std::endl;
	displayArray(integers, intSize, "Before doubling");
	iter(integers, intSize, doubleElement<int>);
	displayArray(integers, intSize, "After doubling");

	// Test 3: String array 
	std::cout << "\n--- Test 3: String array ---" << std::endl;
	std::string strings[] = {"Hello", "World", "CPP", "Templates"};
	size_t strSize = sizeof(strings) / sizeof(strings[0]);
	
	displayArray(strings, strSize, "Original strings");
	std::cout << "Using printElement: ";
	iter(strings, strSize, printElement<std::string>);
	std::cout << std::endl;
	
	std::cout << "Doubling strings:" << std::endl;
	iter(strings, strSize, doubleElement<std::string>);
	displayArray(strings, strSize, "After doubling");

	// Test 4: Character array with modifying function
	std::cout << "\n--- Test 4: Character array modification ---" << std::endl;
	char chars[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charSize = sizeof(chars) / sizeof(chars[0]);
	
	displayArray(chars, charSize, "Original chars");
	iter(chars, charSize, makeUppercase);
	displayArray(chars, charSize, "After uppercase");
	
	iter(chars, charSize, incrementElement<char>);
	displayArray(chars, charSize, "After increment");

	// Test 5: Float array
	std::cout << "\n--- Test 5: Float array ---" << std::endl;
	float floats[] = {1.1f, 2.2f, 3.3f, 4.4f};
	size_t floatSize = sizeof(floats) / sizeof(floats[0]);
	
	displayArray(floats, floatSize, "Original floats");
	iter(floats, floatSize, doubleElement<float>);
	displayArray(floats, floatSize, "After doubling");

	std::cout << "\n=== All tests completed! ===" << std::endl;
	return 0;
}