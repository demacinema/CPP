/* demrodri@student.42wolfsburg.de
   CPP07 - ex00 - whatever - main.cpp */

#include "whatever.hpp"
#include <string>
#include <iostream>

void testSubject()
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void test()
{
	std::cout << "=== COMPREHENSIVE TEMPLATE TESTS ===" << std::endl;
	
	// Test 1: Basic integers
	std::cout << "\n--- Test 1: Basic integers ---" << std::endl;
	int ia = 10, ib = 20;
	std::cout << "Before: ia=" << ia << ", ib=" << ib << std::endl;
	::swap(ia, ib);
	std::cout << "After swap: ia=" << ia << ", ib=" << ib << std::endl;
	std::cout << "min(" << ia << ", " << ib << ") = " << ::min(ia, ib) << std::endl;
	std::cout << "max(" << ia << ", " << ib << ") = " << ::max(ia, ib) << std::endl;

	// Test 2: Equal values (edge case - should return second parameter)
	std::cout << "\n--- Test 2: Equal values (edge case) ---" << std::endl;
	int equal1 = 42, equal2 = 42;
	std::cout << "equal1=" << equal1 << ", equal2=" << equal2 << std::endl;
	std::cout << "min(equal1, equal2) = " << ::min(equal1, equal2) << " (should be equal2)" << std::endl;
	std::cout << "max(equal1, equal2) = " << ::max(equal1, equal2) << " (should be equal2)" << std::endl;

	// Test 3: Negative numbers
	std::cout << "\n--- Test 3: Negative numbers ---" << std::endl;
	int neg1 = -15, neg2 = -5;
	std::cout << "Before: neg1=" << neg1 << ", neg2=" << neg2 << std::endl;
	::swap(neg1, neg2);
	std::cout << "After swap: neg1=" << neg1 << ", neg2=" << neg2 << std::endl;
	std::cout << "min(" << neg1 << ", " << neg2 << ") = " << ::min(neg1, neg2) << std::endl;
	std::cout << "max(" << neg1 << ", " << neg2 << ") = " << ::max(neg1, neg2) << std::endl;

	// Test 4: Floating point numbers with precision
	std::cout << "\n--- Test 4: Floating point precision ---" << std::endl;
	double d1 = 3.14159, d2 = 3.14160;
	std::cout << "d1=" << d1 << ", d2=" << d2 << std::endl;
	std::cout << "min(d1, d2) = " << ::min(d1, d2) << std::endl;
	std::cout << "max(d1, d2) = " << ::max(d1, d2) << std::endl;

	// Test 5: Characters (ASCII comparison)
	std::cout << "\n--- Test 5: Character comparison ---" << std::endl;
	char c1 = 'Z', c2 = 'a';  // Upper vs lower case
	std::cout << "c1='" << c1 << "' (ASCII:" << (int)c1 << "), c2='" << c2 << "' (ASCII:" << (int)c2 << ")" << std::endl;
	std::cout << "min(c1, c2) = '" << ::min(c1, c2) << "'" << std::endl;
	std::cout << "max(c1, c2) = '" << ::max(c1, c2) << "'" << std::endl;

	// Test 6: String lexicographical comparison
	std::cout << "\n--- Test 6: String lexicographical comparison ---" << std::endl;
	std::string s1 = "apple", s2 = "application";
	std::cout << "s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << std::endl;
	std::cout << "min(s1, s2) = \"" << ::min(s1, s2) << "\"" << std::endl;
	std::cout << "max(s1, s2) = \"" << ::max(s1, s2) << "\"" << std::endl;

	// Test 7: Empty vs non-empty string
	std::cout << "\n--- Test 7: Empty vs non-empty string ---" << std::endl;
	std::string empty = "", nonEmpty = "hello";
	std::cout << "empty=\"" << empty << "\", nonEmpty=\"" << nonEmpty << "\"" << std::endl;
	std::cout << "min(empty, nonEmpty) = \"" << ::min(empty, nonEmpty) << "\"" << std::endl;
	std::cout << "max(empty, nonEmpty) = \"" << ::max(empty, nonEmpty) << "\"" << std::endl;

	// Test 8: Numbers vs strings of numbers (different behavior)
	std::cout << "\n--- Test 8: Numeric vs lexicographic comparison ---" << std::endl;
	int num1 = 2, num2 = 10;
	std::string str1 = "2", str2 = "10";
	std::cout << "Numeric: min(" << num1 << ", " << num2 << ") = " << ::min(num1, num2) << std::endl;
	std::cout << "String: min(\"" << str1 << "\", \"" << str2 << "\") = \"" << ::min(str1, str2) << "\"" << std::endl;

	// Test 9: Large values (edge case for overflow)
	std::cout << "\n--- Test 9: Large values ---" << std::endl;
	long long big1 = 9223372036854775806LL, big2 = 9223372036854775807LL;
	std::cout << "big1=" << big1 << ", big2=" << big2 << std::endl;
	::swap(big1, big2);
	std::cout << "After swap: big1=" << big1 << ", big2=" << big2 << std::endl;
}

int main()
{
	testSubject();
	std::cout << std::endl;
	test();
}