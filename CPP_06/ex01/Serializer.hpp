/* demrodri@student.42wolfsburg.de
   CPP06 - ex01 - serializer - Serializer.hpp */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint> // for uintptr_t

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr); // Converts a pointer to an integer type
		static Data* deserialize(uintptr_t raw); // Converts an integer type back to a pointer
};

#endif