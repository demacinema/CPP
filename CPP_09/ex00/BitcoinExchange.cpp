/* demrodri@student.42wolfsburg.de
   CPP09 - ex00 - btc - BitcoinExchange.cpp */

#include "BitcoinExchange.hpp"

const char* BitcoinExchange::ConException::what() const throw() // Exception for connection errors or other specific conditions
{
	return "Missing 'data.csv' Data file";
}

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other) return *this;
	this->_data = other._data;
	return (*this);
}

void BitcoinExchange::InitData() // Initialize data from a file named "data.csv"
// 1. Open the file "data.csv"
// 2. Read each line, split by comma to get date and value
// 3. Store the date and value in the _data map
// 4. Handle exceptions for file not found or other issues
{
	std::ifstream inputFile("data.csv"); // Open the file
	if (!inputFile.is_open()) // If the file cannot be opened,
		throw BitcoinExchange::ConException();

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

// In summary, the InitData function reads Bitcoin exchange data from a CSV file
// and stores it in a map for later retrieval.


void    date_modifier(int &day, int &month, int &year)
// Function to modify the date by going back one day
// 1. If the day is not the first, simply decrement the day.
// 2. If the day is the first, check the month:
//    - If the month is May, July, October, or December, set the day
//      to 30 and decrement the month.
//    - If the month is February, set the day to 28 (ignoring leap
//      years for simplicity) and decrement the month.
//    - If the month is January, set the day to 31, decrement the month
//      to December, and decrement the year.

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

// In summary, the date_modifier function adjusts the given date by moving it back one day,
// taking into account the varying number of days in each month and the transition between months and years.


std::map<std::string, double>::iterator BitcoinExchange::FindData(std::string date)
// Function to find data for a specific date in the map
// 1. Check if the date exists in the _data map.
// 2. If it does, return the iterator to that date.
// 3. If it does not, modify the date by going back one day until a
//    valid date is found.
// 4. Return the iterator to the found date.

{
	std::map<std::string, double>::iterator it = _data.find(date); // Try to find the date in the map
	std::istringstream iss(date); // Create a string stream from the date
	int year, month, day; // Variables to hold year, month, and day
	char dash; // Variable to hold the dash character
	iss >> year >> dash >> month >> dash >> day; // Parse the date into year, month, and day
	std::ostringstream oss; // Create an output string stream to format the new date
	std::string new_date; // Variable to hold the new date string
	while (it == _data.end()) // While the date is not found in the map
	{
		date_modifier(day, month, year); // Modify the date by going back one day
		oss.str(""); // Clear the string stream
		if (month < 10 && day > 9) // Format the new date string with leading zeros if necessary
			oss << year << "-0" << month << '-' << day; // e.g., 2023-04-15
		else if  (month < 10 && day < 10) // Both month and day need leading zeros
			oss << year << "-0" << month << "-0" << day; // e.g., 2023-04-05
		else if  (month > 9 && day < 10) // Only day needs leading zero
			oss << year << '-' << month << "-0" << day; // e.g., 2023-11-07
		else // No leading zeros needed
			oss << year << '-' << month << '-' << day; // e.g., 2023-12-25
		new_date = oss.str(); // Get the new date string. We need the new date in string format to search in the map because
		// the map key is a string. So, we need to convert the modified date back to string format.
		// e.g.: if the modified date is 2023, 4, 5, we need to convert it to "2023-04-05"
		// to do that, we first format it using the string stream (oss) and then get the string using oss.str().
		// then we search for the new date in the map.
		// then we update the iterator to point to the new date in the map.
		// this process continues until we find a valid date in the map.
		// finally, we return the iterator to the found date.
		// this way, we can find the closest previous date if the exact date is not found.
		// this is useful for historical data where some dates may be missing.
		// for example, if we are looking for data on 2023-04-10 but it is not available,
		// we can find the data for 2023-04-09 instead.
		// this ensures that we always get some data, even if the exact date is not present.
		// this is especially important for financial data like Bitcoin prices.
		// it helps to provide a fallback mechanism to get the closest available data.
		it = _data.find(new_date);  // Try to find the new date in the map
	}
	return (it);
}

// In summary, the FindData function searches for a specific date in the Bitcoin exchange data map.
// If the date is not found, it modifies the date by going back one day at a time until a valid date is found.
// It then returns an iterator to the found date in the map.