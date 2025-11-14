/* demrodri@student.42wolfsburg.de
   CPP09 - ex00 - btc - main.cpp */

#include "BitcoinExchange.hpp"

bool	correct_date(std::string date)
{
	std::istringstream iss(date);
	int year, month, day;
	char dash;

	if (!(iss >> year >> dash >> month >> dash >> day))
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

std::string trim(std::string str){
	size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos)
		return ("");
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, last - first + 1);
	
}

int	ft_error(int i)
{
	if (i == 0)
		std::cerr << "Wrong amount of arguments" << std::endl;
	if (i == 1)
		std::cerr << "Wrong file path" << std::endl;
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error(0));
	BitcoinExchange data;
	try{data.InitData();}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
		return (0);}
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
		return (ft_error(1));
	std::map<std::string, double> map;
	std::string line;
	double value;
	std::map<std::string, double>::iterator it;
	while (std::getline(inputFile, line)){
		std::istringstream iss(line);
		std::string date;
		if (std::getline(iss, date, '|')){
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
			else{
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