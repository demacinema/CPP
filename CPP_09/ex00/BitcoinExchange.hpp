/* demrodri@student.42wolfsburg.de
   CPP09 - ex00 - btc - BitcoinExchange.hpp */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream> // for file handling - used in InitData() in BitcoinExchange.cpp
#include <sstream> 
#include <string>
#include <iomanip> // for std::setprecision - used in main.cpp
#include <cmath> // for std::floor - used in rounding (in main.cpp)
#include <climits> // for INT_MAX


class BitcoinExchange
// Class to handle Bitcoin exchange data:
// 1. Initialize data from a file, 
// 2. Find data for a specific date,
// 3. Handle exceptions for invalid input.
{
	private:
		std::map<std::string, double> _data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&operator=(const BitcoinExchange& other);

		void    InitData(); // Initialize data from a file named "data.csv"
		std::map<std::string, double>::iterator   FindData(std::string date); // Find data for a specific date in the map

		class IntException : public std::exception // Exception for invalid integer input
		{
		public:
			virtual const char* what() const throw();
		};

		class NegException : public std::exception // Exception for negative input
		{
			public:
				virtual const char* what() const throw();
		};

		class ConException : public std::exception // Exception for connection errors or other specific conditions
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif