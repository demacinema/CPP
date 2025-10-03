/* demrodri@student.42wolfsburg.de
   CPP06 - ex01 - serializer - Data.hpp */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

class Data
{
	private:
		Data(const Data&);
		Data& operator=(const Data&);

	public:
		int				rooms;
		std::string		address;

		Data();
		~Data();
};
std::ostream& operator<<(std::ostream& os, const Data& data);

#endif