/* demrodri@student.42wolfsburg.de
   CPP06 - ex01 - serializer - main.cpp */

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data House;
	House.rooms = 5;
	House.address = "Rua do Caralho, 42";

	Data* originalPtr = &House; // store the memory location of the object

	uintptr_t serial = Serializer::serialize(originalPtr);
	std::cout << House; // to show the content of the original object
	std::cout << "Serialized data: " << serial << std::endl << std::endl; // to show the serialized value

	Data* deserial = Serializer::deserialize(serial);
	std::cout << *deserial; // to show the content of the deserialized object
	std::cout << "Deserialized data:" << deserial << std::endl; // to indicate the deserialization step

	std::cout << std::endl;
	std::cout << "Original pointer: " << originalPtr << std::endl;
	std::cout << "Deserialized pointer: " << deserial << std::endl;
	std::cout << "Are both pointers equal? " << (originalPtr == deserial ? "Yes" : "No") << std::endl;

	std::cout << "\nAccessing object through deserialized pointer:" << std::endl;
	std::cout << "Rooms: " << deserial->rooms << std::endl;
	std::cout << "Address: " << deserial->address << std::endl;

	return 0;
}

// This converts the memory address to a plain number.
// GPS coordinates (37.7749° N, 122.4194° W) into a single number (3777492204194)