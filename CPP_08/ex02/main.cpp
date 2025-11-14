/* demrodri@student.42wolfsburg.de
   CPP08 - ex02 - mutantStack - main.cpp */

#include "MutantStack.hpp"
#include <list> // for std::list

void testOnSubject() // test as per subject example
{
	std::cout << "\n[SUBJECT TEST]" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3); mstack.push(5); 
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it; 
	}
	std::stack<int> s(mstack); 
}

void testOnSubjectWithList() // additional test with std::list
{
	std::cout << "\n[SUBJECT TEST WITH LIST]" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3); 
	list.push_back(5); 
	list.push_back(737);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it; 
	} 
}

void test() // additional test with copy constructor and assignment operator
{
	MutantStack<int> mstack;

	for (int i = 0; i < 10; i++) // push numbers 0-9 onto stack
		mstack.push(i);

	// iterate using normal iterator
	std::cout << "\nORIGINAL STACK" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) // print original stack
	{
		std::cout << *it << std::endl;
		*it = *it + 100;
	}

	// iterate using constant iterator
	std::cout << "\nCONSTANT STACK" << std::endl;
	for (MutantStack<int>::const_iterator it = mstack.cbegin(); it != mstack.cend(); it++) // print modified stack
	{
		std::cout << *it << std::endl;
	}

	// test copy constructor
	std::cout << "\nCOPIED STACK" << std::endl;
	MutantStack<int> mstack2(mstack); // copy constructor

	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); it++) // print copied stack
	{
		std::cout << *it << std::endl; // print copied stack, before modification
		*it = *it + 100; // modify copied stack
	}

	// test assignment operator
	std::cout << "\nCOPIED STACK AFTER ADDING" << std::endl;
	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); it++) // print modified copied stack
	{
		std::cout << *it << std::endl;
	}

	// ensure original stack is unchanged
	std::cout << "\nORIGINAL STACK" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) // print original stack again, showing it is unchanged
	{
		std::cout << *it << std::endl;
	}
}

void reverseTest()
{
	MutantStack<double> mstack; // using double type to show template works with other types

	// iterate using reverse iterator
	std::cout << "\nREVERSE ITERATOR TEST" << std::endl; 
	for (int i = 0; i < 10; i++) // push numbers 0-9 onto stack
	{
		mstack.push(i);
	}

	// iterate using reverse iterator
	std::cout << "\nORIGINAL STACK (REVERSE)" << std::endl;
	for (MutantStack<double>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++) // print original stack in reverse
	{
		std::cout << *it << std::endl; // print original stack
		*it = *it + 100; // modify original stack
	}

	// iterate using constant reverse iterator
	std::cout << "\nMODIFIED STACK (REVERSE)" << std::endl;
	for (MutantStack<double>::const_reverse_iterator it = mstack.crbegin(); it != mstack.crend(); it++) // print modified stack in reverse
	{
		std::cout << *it << std::endl;
	}
}

int main()
{
	testOnSubject();
	std::cout << std::endl;
	testOnSubjectWithList();
	std::cout << std::endl;
	test();
	reverseTest();
}


// int main()
// {
// MutantStack<int>
// mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }