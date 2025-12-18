/* demrodri@student.42wolfsburg.de
   CPP09 - ex00 - btc - BitcoinExchange.cpp */

#include "BitcoinExchange.hpp"

const char* BitcoinExchange::ConException::what() const throw() // Exception for file connection errors
{
	return "Error: could not open file.";
}

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other) // if it is the same object, just return *this, as no need to copy
		return *this;

	this->_data = other._data; // copy the data from other to this object
	return (*this);
}


// Reads Bitcoin exchange data from a CSV file and stores it in a map for later retrieval.
void BitcoinExchange::InitData() // Initialize data from a file named "data.csv"
{
	std::ifstream inputFile("data.csv"); // Open the file
	if (!inputFile.is_open()) // If the file cannot be opened,
		throw BitcoinExchange::ConException(); // create the exception object and throw it - "Stop here and send this error up"

	std::string line; 
	std::string date;
	double value;
	while (std::getline(inputFile, line)) // Read each line from the file
	{
		std::istringstream iss(line); // Create a string stream from the line
		std::getline(iss, date, ','); // Get the date (first part before comma)
		iss >> value; // Get the value (second part after comma)
		this->_data[date] = value; // Store the date and value in the map
	}
}



// Adjusts the given date by moving it back one day
// 1. If the day is not the first, simply decrement the day.
// 2. If the day is the first but the month is not January, decrement the month and set the day to the last day of the previous month.
// 3. If the month is March, check for leap year to determine if February has 28 or 29 days.
// 4. If the day is the first and the month is January, decrement the year, set the month to December, and the day to 31.
void    date_modifier(int &day, int &month, int &year)
{
	if (day != 1) // If the day is not the first of the month
		day--; // Simply decrement the day
	else if (day == 1 && month != 1) // If the day is the first but the month is not January
	{
		if (month == 5 || month == 7 || month == 10 || month == 12) // Months with 30 days, set day to 30
		{
			day = 30;
			month--; // Decrement the month
		}
		else if (month == 3) // Leap year check: if year is divisible by 4 and (not divisible by 100 or divisible by 400)
		{
			if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
			{
				day = 29; // If it's a leap year, February can have up to 29 days
				month--; // Decrement the month;
			}
			else
			{
				day = 28; // If it's not a leap year, February can have up to 28 days
				month--; // Decrement the month;
			}
		}
		else // Months with 31 days, set day to 31
		{
			day = 31;
			month--; // Decrement the month
		}
	}
	else if (day == 1 && month == 1) // If the day is the first and the month is January
	{
		year--; // Decrement the year
		day = 31; // Set day to 31
		month = 12; // Set month to December
	}
}


// Searches for a specific date in the Bitcoin exchange data map, and returns an iterator to the found date.
// If the date is not found, it modifies the date by going back one day at a time until a valid date is found.
// It then returns an iterator to the found date in the map.
std::map<std::string, double>::iterator 	BitcoinExchange::FindData(std::string date)
{
//IF FOUND, RETURN IT
	std::map<std::string, double>::iterator it = _data.find(date); // Try to find the date in the map, and get an iterator to it
	if (it != _data.end()) // If the date is found, return the iterator - "early exit"
		return (it);


//IF NOT FOUND, MODIFY DATE UNTIL FOUND
//1. String → Variables
	std::istringstream iss(date); // Create a string stream from the date
	int year, month, day; // Variables to hold year, month, and day
	char dash; // Variable to hold the dash character

	iss >> year >> dash >> month >> dash >> day; // Parse the date, to be able to modify it

	std::ostringstream oss; // Create an output string stream to format the new date ("an empty document")
							// similar to cout, but writes to a string instead of console
	std::string new_date; // Variable to hold the new date string

	while (it == _data.end()) // While the date is not found in the map, decrement the date until found
	{						 // If the data were found above, the iterator would not be equal to end()
		date_modifier(day, month, year); // Modify the date by going back one day

//2. Variables → String
		oss.str(""); // Clear the string stream, so it does not append to previous content
		if (month < 10 && day > 9) // Only month needs leading zero
			oss << year << "-0" << month << '-' << day; // e.g., 2023-04-15
		else if  (month < 10 && day < 10) // Both month and day need leading zeros
			oss << year << "-0" << month << "-0" << day; // e.g., 2023-04-05
		else if  (month > 9 && day < 10) // Only day needs leading zero
			oss << year << '-' << month << "-0" << day; // e.g., 2023-11-07
		else // No leading zeros needed
			oss << year << '-' << month << '-' << day; // e.g., 2023-12-25
		new_date = oss.str(); // Parse back to string, as oss is an ostringstream object
		
		// Get the new date string - e.g: modified date is 2023, 4, 5,need convert it to "2023-04-05"
		// to do that, we first format it using the string stream (oss) and then get the string using oss.str().
		// then we search for the new date in the map.
		// then we update the iterator to point to the new date in the map.

		it = _data.find(new_date);  // Try to find the new date in the map
	}

	return (it);
}