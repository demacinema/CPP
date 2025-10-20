/* demrodri@student.42wolfsburg.de
   CPP07 - ex02 - array - main.cpp */

#include "Array.hpp"

void test()
{
	// Test for array of integers, and index out of bounds exception
	std::cout << "== TEST1 ==" <<std::endl;
	Array<int> a(10);

	for (unsigned int i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	std::cout << a << std::endl;

	try
	{
		std::cout << a[10] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "========" <<std::endl;

	// Test for copy constructor and assignment operator
	std::cout << "\n== COPY TEST ==" <<std::endl;
	Array<int> b(a);
	std::cout << "Array b just created by copy constructor:" << std::endl;
	std::cout << b << std::endl;

	// Modify b and show that a is not affected
	for (unsigned int i = 0; i < 10; i++)
	{
		b[i] = i + 10;
	}
	std::cout << "After modifying b:" << std::endl;
	std::cout << "Array a:" << std::endl;
	std::cout << a << std::endl;
	std::cout << "Array b:" << std::endl;
	std::cout << b << std::endl;

	a = b;
	std::cout << "\n\nAfter assigning b to a:" << std::endl;
	std::cout << "Array a:" << std::endl;
	std::cout << a << std::endl;
	std::cout << "Array b:" << std::endl;
	std::cout << b << std::endl;

	std::cout << "========" <<std::endl;

	// Test negative index
	std::cout << "\n== NEGATIVE INDEX TEST ==" <<std::endl;
	try
	{
		Array<int> arr(5);
		std::cout << "Trying to access arr[-1]..." << std::endl;
		arr[-1] = 0;  // Should throw
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "========" <<std::endl;
	// Test larger array (stress testing)
	std::cout << "\n== LARGE ARRAY TEST ==" <<std::endl;
	Array<int> largeArray(100);
	std::cout << "Created array of size: " << largeArray.size() << std::endl;
	
	// Fill with values
	for (unsigned int i = 0; i < largeArray.size(); i++)
	{
		largeArray[i] = i * 2;
	}
	
	// Verify some values
	std::cout << "largeArray[0] = " << largeArray[0] << std::endl;
	std::cout << "largeArray[50] = " << largeArray[50] << std::endl;
	std::cout << "largeArray[99] = " << largeArray[99] << std::endl;
	
	// Test out of bounds on large array
	try
	{
		std::cout << "Trying to access largeArray[100]..." << std::endl;
		std::cout << largeArray[100] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "========" <<std::endl;

	// Test empty array
	std::cout << "\n== EMPTY ARRAY TEST ==" <<std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;
	try
	{
		std::cout << "Trying to access emptyArray[0]..." << std::endl;
		std::cout << emptyArray[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "========" <<std::endl;

	std::cout << "\n==STRING TEST==" <<std::endl;
	Array<std::string> stra(10);
	for (unsigned int i = 0; i < stra.size(); i++)
	{
		stra[i] = "Hello " + std::to_string(i); // Using std::to_string to convert int to string
	}
	std::cout << stra << std::endl;
}

int main()
{
	test();
	// //This is a check for memory leaks, only works on MacOS with the leaks tool
	// system("leaks array || grep leaked");
	return 0;
}