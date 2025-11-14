/* demrodri@student.42wolfsburg.de
   CPP09 - ex00 - btc - BitcoinExchange.cpp */

#include "BitcoinExchange.hpp"

const char* BitcoinExchange::ConException::what() const throw()
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

void BitcoinExchange::InitData()
{
	std::ifstream inputFile("data.csv");
	if (!inputFile.is_open())
		throw BitcoinExchange::ConException();
	std::string line;
	std::string date;
	double value;
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		std::getline(iss, date, ',');
		iss >> value;
		this->_data[date] = value;
		}
}

void    date_modifier(int &day, int &month, int &year)
{
	if (day != 1)
		day--;
	else if (day == 1 && month != 1)
	{
		if (month == 5 || month == 7 || month == 10 || month == 12)
		{
			day = 30;
			month--;
		}
		else
		{
			day = 31;
			month--;
		}
	}
	else if (day == 1 && month == 1)
	{
		year--;
		day = 31;
		month = 12;
	}
}

std::map<std::string, double>::iterator BitcoinExchange::FindData(std::string date)
{
	std::map<std::string, double>::iterator it = _data.find(date);
	std::istringstream iss(date);
	int year, month, day;
	char dash;
	iss >> year >> dash >> month >> dash >> day;
	std::ostringstream oss;
	std::string new_date;
	while (it == _data.end())
	{
		date_modifier(day, month, year);
		oss.str("");
		if (month < 10 && day > 9)
			oss << year << "-0" << month << '-' << day;
		else if  (month < 10 && day < 10)
			oss << year << "-0" << month << "-0" << day;
		else if  (month > 9 && day < 10)
			oss << year << '-' << month << "-0" << day;
		else
			oss << year << '-' << month << '-' << day;
		new_date = oss.str();
		it = _data.find(new_date); 
	}
	return (it);
}