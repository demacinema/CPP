/* demrodri@student.42wolfsburg.de
   CPP06 - ex01 - serializer - Data.cpp */

#include "Data.hpp"

Data::Data() {}

std::ostream& operator<<(std::ostream& os, const Data& data)
{
	return os << "Data address: " << &data << std::endl;
}