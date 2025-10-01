/* demrodri@student.42wolfsburg.de
   CPP06 - ex00 - convert - main.cpp */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) // Check for valid input (also done in convert)
	{
		std::cerr << "Usage: ./convert <input>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	return (0);
}