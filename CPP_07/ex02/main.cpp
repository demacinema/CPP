/* demrodri@student.42wolfsburg.de
   CPP07 - ex02 - array - main.cpp */

#include "Array.hpp"
#include <sstream>

class ComplexType
{
	public:
		ComplexType() : value(42), name("default") {}
		ComplexType(int v, std::string n) : value(v), name(n) {}

		// Getters to access private members
		int getValue() const { return value; }
		std::string getName() const { return name; }

	private:
		int value;
		std::string name;
};

std::ostream& operator<<(std::ostream& os, const ComplexType& obj)
{
	return os << "{" << obj.getValue() << ", " << obj.getName() << "}";
}

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
		// C++98 compatible int to string conversion
		std::ostringstream oss;
		oss << i;
		stra[i] = "Hello " + oss.str();
		
		// C++11 version (doesn't work with -std=c++98):
		// stra[i] = "Hello " + std::to_string(i);
	}
	std::cout << stra << std::endl;

	// Test complex type
	std::cout << "\n== COMPLEX TYPE TEST ==" << std::endl;
	Array<ComplexType> complexArray(3);
	complexArray[0] = ComplexType(1, "first");
	complexArray[1] = ComplexType(2, "second");
	complexArray[2] = ComplexType(3, "third");
	std::cout << "Complex array:" << std::endl;
	std::cout << complexArray << std::endl;

	// Test copy constructor with complex types
	Array<ComplexType> copiedComplex(complexArray);
	std::cout << "Copied complex array:" << std::endl;
	std::cout << copiedComplex << std::endl;
}

int main()
{
	test();

	return 0;
}