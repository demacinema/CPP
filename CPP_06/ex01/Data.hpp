/* demrodri@student.42wolfsburg.de
   CPP06 - ex01 - serializer - Data.hpp */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

class Data
{
	public:
		int				rooms;
		std::string		address;

		Data();
		~Data();
		Data(const Data& other);
		Data& operator=(const Data& other);
};
std::ostream& operator<<(std::ostream& os, const Data& data);

#endif

// The serialization exercise is about preserving identity:
// making sure that after converting a pointer to a number and back,
// it still points to the exact same object (not just an object with the same values)