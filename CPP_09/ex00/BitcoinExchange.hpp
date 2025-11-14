/* demrodri@student.42wolfsburg.de
   CPP09 - ex00 - btc - BitcoinExchange.hpp */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <climits>


class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&operator=(const BitcoinExchange& other);

		void    InitData();
		std::map<std::string, double>::iterator   FindData(std::string date);

		class IntException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};

		class NegException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class ConException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif