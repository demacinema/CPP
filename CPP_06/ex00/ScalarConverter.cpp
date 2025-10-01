/* demrodri@student.42wolfsburg.de
   CPP06 - ex00 - convert - ScalarConverter.cpp */

#include "ScalarConverter.hpp"

//Don't need to implement "private" methods, as they will never be called.
//Cannonical Form just requires that they get declared

void ScalarConverter::convert(const std::string& input)
{
	// Check for empty input. Is also checked in main, but functions should validate their own input.
	if (input.empty())
	{
		std::cout << "Error: Invalid input" << std::endl;
		return;
	}

	// Handle special cases first
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}

	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}

	// Handle single character input (like 'A'), because otherwise strtod will parse it as 0
	// and we want to display the character itself, not its ASCII value 0
	// Also ensure it's not a digit, because '1' should be treated as number
	// and converted to int 1, not char '1'
	if (input.length() == 1 && !std::isdigit(input[0])) // is a single non-digit character
	{
		char c = input[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return;
	}

	// Parse numeric input, using strtod to handle floats and doubles.
	char* ptr;
	double value = std::strtod(input.c_str(), &ptr); // convert to double first, then cast down as needed

	// Check for parsing errors
	if (ptr == input.c_str() || *ptr != '\0') // if no conversion or extra characters remain
	{
		// Handle case where input ends with 'f' (float notation)
		if (input.back() == 'f')
		{
			std::string temp = input.substr(0, input.length() - 1); // remove the 'f'
			value = std::strtod(temp.c_str(), &ptr); // try converting again
			
			// If ptr doesn't point to end of string after parsing, it's an error
			if (ptr != temp.c_str() + temp.length()) // if failed: could also be written as if (*ptr != '\0')
			{
				std::cout << "Error: Invalid input" << std::endl;
				return;
			}
			// Valid float, continue processing
		}
		else // not a valid number, as it doesn't end with 'f' (probably other random string)
		{
			std::cout << "Error: Invalid input" << std::endl;
			return;
		}
	}

	// Display char conversion
	if (value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl; // outside ASCII range
	}
	else if (value < 32 || value == 127)
	{
		std::cout << "char: Non displayable" << std::endl; // non-printable ASCII
	}
	else
	{
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl; // double to char conversion
	}

	// Display int conversion
	if (value < INT_MIN || value > INT_MAX) // outside int range
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(value) << std::endl; // double to int conversion
	}

	// Display float conversion
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	// used std::fixed and std::setprecision(1) to always show one decimal place
	// std::fixed - ensures that we don't use scientific notation for large/small numbers
	// std::setprecision(1) - sets the number of digits after the decimal point

	// Display double conversion  
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}