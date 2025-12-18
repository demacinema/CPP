/* demrodri@student.42wolfsburg.de
   CPP09 - ex00 - btc - main.cpp */

#include "BitcoinExchange.hpp"
#include <ctime> // for time functions to get current date

// Checks its format and ensures that falls within acceptable ranges
bool	correct_date(std::string date)
{
	// Check if the date format is correct:
	// year: reads an integer, and stores it in year
	// dash: reads the '-' character, and stores it in dash (we don't use it)
	// month: reads an integer, and stores it in month
	// dash: reads the '-' character, and stores it in dash (we don't use it)
	// day: reads an integer, and stores it in day
	std::istringstream iss(date); //input string stream ("similar to cin") to parse the date
	int year, month, day;
	char dash; //"trash" var, to ignore the '-' characters in the date string

	if (!(iss >> year >> dash >> month >> dash >> day))
		return (false);

	// Check if the date is before Bitcoin existed (before 2009-01-02)
	if ((year == 2009 && (month == 1 && day < 2)))
		return (false);

	// Check if the year, month, and day are within valid ranges
	if (((year < 2009) || (month < 1 || month > 12) || (day < 1 || day > 31)))
		return (false);
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);

    // Check if date is in the future
    time_t now = time(0); // time (0) returns the current time in seconds since epoch (Jan 1, 1970)
    tm *ltm = localtime(&now); // localtime converts the time in seconds to a struct tm (local time representation)
    int currentYear = 1900 + ltm->tm_year; // tm_year is the number of years since 1900
    int currentMonth = 1 + ltm->tm_mon; // tm_mon is the number of months since January (0-11)
    int currentDay = ltm->tm_mday; // tm_mday is the day of the month (1-31)
    if (year > currentYear)
        return (false);
    if (year == currentYear && month > currentMonth)
        return (false);
    if (year == currentYear && month == currentMonth && day > currentDay)
        return (false);

	// Leap year check: if year is divisible by 4 and (not divisible by 100 or divisible by 400)
	if (month == 2)
	{
		if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		{
			if (day > 29) // If it's a leap year, February can have up to 29 days
				return (false);
		}
		else
		{
		if (day > 28) // If it's not a leap year, February can have up to 28 days
			return (false);
		}
	}

	return (true);
}

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

// Main function to read Bitcoin exchange data from a file
// 1. Check if the correct number of arguments is provided.
// 2. Initialize a BitcoinExchange object and call InitData to load data from "data.csv".
// 3. Open the input file specified in the command line argument.
// 4. Read each line, split by '|' to get date and value.
// 5. Validate the date and value, handle errors for invalid input.
// 6. If valid, find the corresponding data in the BitcoinExchange object and print.
// 7. Handle exceptions for file not found or other issues.	
int main(int argc, char **argv)
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

	std::ifstream inputFile(argv[1]); // Create file stream and open file specified in the command line argument
	if (!inputFile.is_open()) // If not opened,
		return (ft_error(1));

// Read each line, split by '|' to get date and value
	// std::map<std::string, double> map; // Not needed, as the map in BitcoinExchange class is used
	std::string line;
	double value;

	std::map<std::string, double>::iterator it; // Iterator (pointer) to hold the result of FindData

	while (std::getline(inputFile, line)) // Read each line until EOF - getline (origin stream, result string)
	{									  // Every iteration stops at a new line character (getline(inputFile, line, '\n')) by default
		std::istringstream iss(line); // Create a string stream for each line, so we can parse it (as we did in correct_date)
		std::string date;

		if (std::getline(iss, date, '|')) // getline (stream, string, reads up to delimiter) - discards the delimiter, moves 2 next char
		{                                 // Split the line by '|' to get the date. ex: "2023-03-15 | 1500" becomes "2023-03-15 "
			if (trim(date) == "date") // Skip the header line (date | value)
				continue ;
			else if (!correct_date(trim(date))) // Validate the date format and range
				std::cerr << "Error: bad input => " << date << std::endl;
			else if (!(iss >> value)) // Try to read the value (after '|') as double
				std::cerr << "Error: bad value" << std::endl;
			else if (value < 0) // Check for negative value
				std::cerr << "Error: not a positive number" << std::endl;
			else if (value > INT_MAX) // Check for excessively large value
				std::cerr << "Error: too large number" << std::endl;
			else // If all checks pass, find the data and print the result
			{
				date = trim(date); // Trim whitespace from date
				it = data.FindData(date); // Find the corresponding data for the date
				std::cout << date << " => " << value << " = " << value * it->second << std::endl; // Print date, value, and calculated exchange rate
			}
		}
		else // If the line cannot be split properly,
			std::cerr << "Error: bad input => " << date << std::endl;
	}
	inputFile.close(); // Close the input file
	
	return (0);
}

