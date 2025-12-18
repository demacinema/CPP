/* demrodri@student.42wolfsburg.de
   CPP09 - ex00 - btc - BitcoinExchange.hpp */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream> // for std::exception
#include <map> // for std::map
#include <string> // for std::string
#include <fstream> // (file stream) - for file handling - used in InitData() in BitcoinExchange.cpp
#include <sstream> // (string stream) - for string stream parsing - used in InitData() and FindData()

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


		// Functions
		void    InitData(); // Initialize data from a file named "data.csv"

		std::map<std::string, double>::iterator 	FindData(std::string date); // Find data for a specific date in the map
												  //FindData returns a pointer-like object that points to the found element in the map.


		// Exceptions
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

/*
Analogy:
Action	Real life								Code
throw	Throwing a ball							throw ConException();
catch	Catching a ball							catch (std::exception &e)
what()	Reading the message on the ball			e.what()

main.cpp                          BitcoinExchange.cpp
────────                          ────────────────────
try {                             
    data.InitData(); ──────────►  InitData() {
                                      if (!file.is_open())
                     ◄──────────          throw ConException();
}                                 }
catch (std::exception &e) {       
    // Error handled here         
    e.what() → "Error: could not open file."
}

Summary:
BitcoinExchange.cpp	throw	"There's a problem, I can't handle it"
main.cpp	try/catch	"I'll watch for problems and handle them"

It's about separation of responsibilities:
BitcoinExchange.cpp	Detect problems (low-level logic)
main.cpp	Decide what to do about problems (high-level control)

The employee detects the problem but lets the boss decide what to do:

BitcoinExchange.cpp	Employee: "Boss, there's a fire!" (reports problem)
main.cpp	Boss: "Call firefighters" or "Evacuate" (decides action)
*/