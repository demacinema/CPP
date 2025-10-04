/* demrodri@student.42wolfsburg.de
   CPP06 - ex02 - realtype - main.cpp */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int n = rand() % 3; // Generates a random number between 0 and 2
	switch (n)
	{
		case 0:
			std::cout << "Class A generated" << std::endl;
			return new A();
		case 1:
			std::cout << "Class B generated" << std::endl;
			return new B();
		case 2:
			std::cout << "Class C generated" << std::endl;
			return new C();
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) // if obj can be cast to A*, meaning it is of type A
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) // if obj can be cast to B*, meaning it is of type B
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) // if obj can be cast to C*, meaning it is of type C
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Unknown" << std::endl; // in case obj is not of type A, B, or C
	}
}

void identify(Base& p)
{
	try // try to dynamic_cast obj to A&. Dynamic cast throws an exception if it fails. I used A&,
	// because if I use A* it will always succeed, returning NULL if it fails.
	// Using references instead of pointers to test the other way of dynamic casting.
	// The (void) is used to avoid compiler warnings about unused variables.
	// Explaining better: if the dynamic_cast succeeds, it returns a reference to the object,
	// which is then cast to void to indicate that we don't care about the value itself,
	// we just want to know if the cast was successful. If the cast fails, it throws an exception,
	// which we catch and ignore, allowing the program to continue executing.
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception& e)
	{
		(void)e;
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception& e)
	{
		(void)e;
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception& e)
	{
		(void)e;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	Base* testptr;

	std::cout << "=================pointer" << std::endl;
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;

	std::cout << "=================reference" << std::endl;
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;

	return 0;
}