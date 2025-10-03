/* demrodri@student.42wolfsburg.de
   CPP06 - ex01 - serializer - Serializer.cpp */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	std::cout << "-------------------" << std::endl
			  << "Serializing data..." << std::endl
			  << "-------------------" << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	std::cout << "-------------------" << std::endl
			  << "Deserializing data..." << std::endl
			  << "-------------------" << std::endl;
	return reinterpret_cast<Data*>(raw);
}