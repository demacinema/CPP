/* demrodri@student.42wolfsburg.de
   CPP06 - ex00 - convert - ScalarConverter.hpp */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cmath> // for mathematical functions if needed
#include <cstdlib> //strtod
#include <cctype> // isdigit
#include <climits> // INT_MAX, INT_MIN
#include <string> // std::string
#include <iostream> // std::cout, std::endl
#include <iomanip> // std::setprecision

class ScalarConverter
{
	private:
		// all private to prevent instantiation (utility class only)
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(const std::string& input);
};

#endif