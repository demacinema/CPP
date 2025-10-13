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
	if (p == nullptr)
		return;
		
	if (dynamic_cast<A*>(p))
		std::cout << "----> A identified!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "----> B identified!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "----> C identified!" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "----> A identified!" << std::endl;
		return;
	} catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "----> B identified!" << std::endl;
		return;
	} catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "----> C identified!" << std::endl;
	}
	catch (std::exception&)
	{
		std::cout << "Unknown type" << std::endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL)); // reset seed for rand()
	Base* testptr;

	std::cout << "==== POINTER ==== " << std::endl;
	std::cout << "1: " << std::endl;
	testptr = generate();
	identify(testptr);
	delete testptr;	
	std::cout << "2: " << std::endl;	
	testptr = generate();
	identify(testptr);
	delete testptr;
	std::cout << "3: " << std::endl;
	testptr = generate();
	identify(testptr);
	delete testptr;
	std::cout << "4: " << std::endl;
	testptr = generate();
	identify(testptr);
	delete testptr;
	std::cout << "5: " << std::endl;
	testptr = generate();
	identify(testptr);
	delete testptr;

	std::cout << "\n==== REFERENCE ==== " << std::endl;
	std::cout << "1: " << std::endl;
	testptr = generate();
	identify(*testptr);
	delete testptr;
	std::cout << "2: " << std::endl;
	testptr = generate();
	identify(*testptr);
	delete testptr;
	std::cout << "3: " << std::endl;
	testptr = generate();
	identify(*testptr);
	delete testptr;
	std::cout << "4: " << std::endl;
	testptr = generate();
	identify(*testptr);
	delete testptr;
	std::cout << "5: " << std::endl;
	testptr = generate();
	identify(*testptr);
	delete testptr;

	return 0;
}