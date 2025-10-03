/* demrodri@student.42wolfsburg.de
   CPP06 - ex01 - serializer - main.cpp */

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data doom1;

	Serializer::serialize(&doom1);
	std::cout << "Serialized " << doom1 << std::endl;

	std::cout << doom1 << std::endl;
	uintptr_t raw1 = Serializer::serialize(&doom1);
	std::cout << std::endl;


	Data* doom3 = Serializer::deserialize(raw1);
	std::cout << std::endl;
	
	std::cout << "- Deserialzed " << doom3 << std::endl;
	std::cout << *doom3 << std::endl;
}