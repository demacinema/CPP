/* demrodri@student.42wolfsburg.de
   CPP06 - ex01 - serializer - Data.cpp */

#include "Data.hpp"

Data::Data() {}
Data::~Data() {}
Data::Data(const Data& other) { *this = other; }
Data& Data::operator=(const Data& other)
{
	if (this != &other)
	{
		this->rooms = other.rooms;
		this->address = other.address;
	}
	return *this;
}


std::ostream& operator<<(std::ostream& os, const Data& data)
{
	return os << "Data address: " << &data << std::endl
			  << "Rooms: " << data.rooms << std::endl
			  << "Adress: " << data.address << std::endl;
}