/* demrodri@student.42wolfsburg.de
   CPP09 - ex00 - btc - main.cpp */

#include "BitcoinExchange.hpp"

bool	correct_date(std::string date)
// Function to check if the date is valid
// 1. Split the date string into year, month, and day.
// 2. Check if the year is between 2009 and 2024, month is between 1 and 12, and day is between 1 and 31.
// 3. Handle special cases for months with fewer than 31 days and February.
// 4. Return true if the date is valid, false otherwise.	
{
	std::istringstream iss(date);
	int year, month, day;
	char dash;

	if (!(iss >> year >> dash >> month >> dash >> day)) // Check if the date format is correct:
	// 1. Use istringstream to parse the date string.
	// 2. Expect the format to be "YYYY-MM-DD" with dashes as separators.
	// 3. If parsing fails, return false.
	// 4. If the format is correct, proceed to validate the date components.
		return (false);
	if ((year == 2009 && (month == 1 && day < 2)))
		return (false);
	if (year == 2024 && month >= 2 && day > 15)
		return (false);
	if (((year < 2009 || year > 2024) || (month < 1 || month > 12) || (day < 1 || day > 31)))
		return (false);
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2)
		{
		if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		{
			if (day > 29)
				return (false);
		}
		else
		{
		if (day > 28)
			return (false);
		}
	}
	return (true);
}

// In summary, the correct_date function validates a date string by checking its format and ensuring
// that the year, month, and day components fall within acceptable ranges, including handling
// special cases for months with fewer days and leap years.

std::string trim(std::string str)// trim leading and trailing whitespace
{
	size_t first = str.find_first_not_of(" \t"); //first character that is not a space or tab
	if (first == std::string::npos) //if first contains only spaces and tabs (npos)
		return ("");
	size_t last = str.find_last_not_of(" \t"); //last character that is not a space or tab
	return str.substr(first, last - first + 1);
	// substr(pos, len): returns a substring starting at position pos with length len (+1 to include the last character)
}

int	ft_error(int i)
{
	if (i == 0)
	{
		std::cerr << "Wrong amount of arguments" << std::endl;
		// std::cerr << "Error: could not open file." << std::endl;
	}
	if (i == 1)
	{
		std::cerr << "Wrong file path" << std::endl;
		// std::cerr << "Error: could not open file." << std::endl;
	}
	return (1);
}

int main(int argc, char **argv)
// Main function to read Bitcoin exchange data from a file
// 1. Check if the correct number of arguments is provided.
// 2. Initialize a BitcoinExchange object and call InitData to load data from "data.csv".
// 3. Open the input file specified in the command line argument.
// 4. Read each line, split by '|' to get date and value.
// 5. Validate the date and value, handle errors for invalid input.
// 6. If valid, find the corresponding data in the BitcoinExchange object and print the
//    date, value, and the calculated exchange rate.
// 7. Handle exceptions for file not found or other issues.	

{
	if (argc != 2)
		return (ft_error(0));

	BitcoinExchange data;
	try
	{
		data.InitData(); //Load data from "data.csv"
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}

// Open the input file specified in the command line argument
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
		return (ft_error(1)); // If the file cannot be opened, return an error

// Read each line, split by '|' to get date and value
	std::map<std::string, double> map;
	std::string line;
	double value;
	std::map<std::string, double>::iterator it; // Iterator to hold the result of FindData
	while (std::getline(inputFile, line)) // Read each line from the input file, while there are lines to read
	{
		std::istringstream iss(line);
		std::string date;
		if (std::getline(iss, date, '|')) // Split the line by '|' to get the date. ex: "2023-03-15 | 1500" becomes "2023-03-15 "
		{
			if (trim(date) == "date")
				continue ;
			else if (!correct_date(trim(date)))
				std::cerr << "Error: bad input => " << date << std::endl;
			else if (!(iss >> value))
				std::cerr << "Error: bad value" << std::endl;
			else if (value < 0)
				std::cerr << "Error: not a positive number" << std::endl;
			else if (value > INT_MAX)
				std::cerr << "Error: too large number" << std::endl;
			else
			{
				date = trim(date);
				it = data.FindData(date);
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << date << std::endl;
	}
	inputFile.close();
}

// In summary, the main function orchestrates the reading and processing of Bitcoin exchange data
// from a specified input file, utilizing the BitcoinExchange class to load historical data,
// validate input dates and values, and compute exchange rates while handling potential errors
// and exceptions.

