/* demrodri@student.42wolfsburg.de
   CPP07 - ex01 - iter - main.cpp */

#include <iostream>
#include "iter.hpp"

// Test functions for each overload

// 1. Regular function - tests GENERIC overload
void printNumber(const int& x)
{ 
	std::cout << x << " "; 
}

// 2. Template function (const) - tests CONST TEMPLATE POINTER overload
template<typename T>
void showValue(const T& x)
{ 
	std::cout << "[" << x << "] "; 
}

// 3. Template function (non-const) - tests NON-CONST TEMPLATE POINTER overload
template<typename T>
void addOne(T& x)
{ 
	x++; 
}

int main()
{
	std::cout << "=== Testing iter overloads ===" << std::endl;
	
	int numbers[] = {1, 2, 3, 4, 5};
	
	// Test 1: Generic overload (regular function) - void (printNumber(const int& x)
	std::cout << "1. Regular function: ";
	iter(numbers, 5, printNumber);
	std::cout << std::endl;
	
	// Test 2: Const template pointer overload - void showValue(const T& x)
	std::cout << "2. Template const function: ";
	iter(numbers, 5, showValue);
	std::cout << std::endl;
	
	// Test 3: Non-const template pointer overload - void addOne(T& x)
	int modifyArray[] = {10, 20, 30};
	std::cout << "3. Template non-const function:" << std::endl;
	std::cout << "   Before: ";
	for (int i = 0; i < 3; i++)
		std::cout << modifyArray[i] << " ";
	std::cout << std::endl;
	
	iter(modifyArray, 3, addOne<int>); //non-const template functions need explicit instantiation when there are multiple matching overloads
	
	std::cout << "   After:  ";
	for (int i = 0; i < 3; i++) std::cout << modifyArray[i] << " ";
	std::cout << std::endl;
	
	// Test with different array types
	float floats[] = {1.5f, 2.5f, 3.5f};
	std::cout << "4. Float array: ";
	iter(floats, 3, showValue);
	std::cout << std::endl;
	
	return 0;
}

