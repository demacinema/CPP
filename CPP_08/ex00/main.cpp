/* demrodri@student.42wolfsburg.de
   CPP08 - ex00 - easyfind - main.cpp */

// The main difference between std::vector, std::deque, and std::list lies in their underlying data structures and performance characteristics
// for different operations. For example, std::vector is implemented as a dynamic array, providing fast random access to elements,
// but can be slow for insertions and deletions in the middle of the container.
// std::deque is implemented as a double-ended queue, allowing fast insertions and deletions at both ends,
// but may have slower random access compared to std::vector.
// std::list is implemented as a doubly linked list, providing fast insertions and deletions at any position,
// but has slower random access since elements are not stored contiguously in memory
// and require traversal from the beginning or end of the list.

// In real life, you would choose between these containers based on your specific use case and performance requirements.
// For example, if you need fast random access and your data size doesn't change frequently, std::vector is a good choice.
// Case of use: storing a list of items that need to be accessed frequently by index, such as a list of scores in a game,
// or a collection of objects that need to be processed in a specific order, like rendering objects in a graphics application,
// or managing a list of tasks in a to-do application where tasks can be added or removed frequently.
// std::deque is useful when you need to frequently add or remove elements from both ends of the container,
// such as implementing a queue or a stack data structure, or managing a sliding window of data in real-time applications,
// or buffering data streams where you need to efficiently add and remove data at both ends.
// std::list is beneficial when you need to frequently insert or delete elements at arbitrary positions within the container,
// such as implementing a playlist where songs can be added or removed dynamically,
// or managing a list of active connections in a network application where connections can be established or terminated frequently,
// or maintaining an ordered list of elements that require frequent reordering or sorting.

#include <vector> // for std::vector (dynamic array): allows fast random access and resizing.
#include <deque> // for std::deque (double-ended queue): allows fast insertion and deletion at both ends
#include <list> // for std::list (doubly linked list): allows fast insertion and deletion at any position
#include <iostream>

#include "easyfind.hpp"

// An iterator, is a generalization of a pointer that allows you to traverse elements in a container
// (like arrays, vectors, lists, etc.) without exposing the underlying structure of the container.
// Iterators provide a uniform way to access elements in different types of containers.
// They support operations like incrementing to move to the next element, dereferencing to access the value of the element,
// and comparison to check if two iterators point to the same position.
// In this code, we use iterators to traverse and access elements in various STL (Standard Template Library) containers (vector, deque, list) in a generic way.
// The displayIter function takes two iterators as parameters: 'it' (the iterator to display) and 'end' (the end iterator of the container).
// It checks if 'it' is not equal to 'end', indicating that the iterator points to a valid element in the container.
// If 'it' is valid, it dereferences the iterator using '*it' to access and display the value of the element it points to.
// If 'it' is equal to 'end', it indicates that the iterator has reached the end of the container,
// and a message "@ iterator end" is displayed instead.

template <typename T>
void displayIter(T it, T end) // display the value of the iterator or indicate if it's at the end
{
	if (it != end)
		std::cout << "Value(dereferenced iterator): " << *it << std::endl;
	else
		std::cout << "End of the container reached" << std::endl;
}

template <typename T>
void findNum(T& container, int toFind) // tries to find 'toFind' in 'container' and displays the result
{
	typename T::iterator it;

	try
	{
		it = easyfind(container, toFind); // easyfind is a function template defined in easyfind.hpp)
		std::cout << "Element[" << toFind << "] found" << std::endl;
	}
	catch (std::exception &e)
	{
		it = container.end();
		std::cout << "Element[" << toFind << "] ";
		std::cout << e.what() << std::endl;
	}
	displayIter(it, container.end()); // display the result
}

template <typename T>
void printContainer(T& container) // prints all elements in the container
{
	typename T::iterator it = container.begin();
	typename T::iterator end = container.end();

	while (it != end)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v; // in real life, used more for static data where size doesn't change often
	std::deque<int> d; // in real life, used for queues and deques where frequent insertions/deletions at both ends are needed
	std::list<int> l; // in real life, used when frequent insertions/deletions at arbitrary positions are needed

	// Fill containers with sample data
	for (int i = 0; i < 100; i+=3)
	{
		v.push_back(i);   // multiples of 3: 0, 3, 6, 9, ..., 297
		d.push_back(i + 1); // offset by 1: 1, 4, 7, 10, ..., 298
		l.push_back(i + 2); // offset by 2: 2, 5, 8, 11, ..., 299
	}

	std::cout <<"\nVECTOR: ";
	printContainer(v);
	std::cout << std::endl;
	findNum(v, 33);
	std::cout<<"------------------------------"<< std::endl;
	findNum(v, 34);
	std::cout<<"------------------------------"<< std::endl;
	findNum(v, 39);

	std::cout<<"\nDEQUE: ";
	printContainer(d);
	std::cout << std::endl;	
	findNum(d, 33);
	std::cout<<"------------------------------"<< std::endl;
	findNum(d, 46);
	std::cout<<"------------------------------"<< std::endl;
	findNum(d, 100);

	std::cout<<"\nLIST: ";
	printContainer(l);
	std::cout << std::endl;
	findNum(l, 33);
	std::cout<<"------------------------------"<< std::endl;
	findNum(l, 80);
	std::cout<<"------------------------------"<< std::endl;
	findNum(l, 98);

	return 0;
}