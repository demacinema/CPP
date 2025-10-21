/* demrodri@student.42wolfsburg.de
   CPP08 - ex02 - mutantStack - MutantStack.hpp */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

// That is how the std::stack<T> is defined in C++ standard library:
// template <class T, class Container = deque<T> > class stack { ... }
// We will extend this std::stack to create our MutantStack.
// The key point is that std::stack uses an underlying container (by default std::deque)
// to store the elements, and we can access that container to get iterators.
// The underlying container is accessible via the protected member 'c' of std::stack.
// This allows us to define begin() and end() functions that return iterators
// to the underlying container, enabling iteration over the stack's elements.

// What differs std::stack from other standard containers?
// std::stack is a container adaptor, meaning it provides a specific interface
// (LIFO - Last In First Out) on top of an underlying container.
// For example, more than it does not provide iterators by default,
// it only allows access to the top element, pushing, and popping elements.
// To do so, we use:
// - to pop: pop() - removes the top element
// - to push: push(const T& value) - adds an element to the top
// - to access the top element: top() - returns a reference to the top element

// this type of container is useful when you need a simple LIFO data structure
// LIFO is useful in scenarios like function call management (call stack),
// expression evaluation, backtracking algorithms, etc.
// In simpler terms, a stack is like a collection of plates where you can only add or remove the top plate.

// It exists because sometimes you need a data structure that follows the LIFO principle,
// and std::stack provides a convenient way to implement that behavior using an underlying container.

// The LIFO principle means that the last element added to the stack
// is the first one to be removed. Imagine a stack of plates:
// - You add plates to the top of the stack (push).
// - When you need a plate, you take the top one off (pop).
// This is different from other data structures like queues (FIFO - First In First Out),
// where the first element added is the first one to be removed.

// In practical terms, std::stack is often used in scenarios like:
// - Function call management (call stack)
// - Expression evaluation (e.g., parsing mathematical expressions)
// - Backtracking algorithms (e.g., maze solving, puzzle solving)
//   where using the FIFO could complicate the logic, as you need to access the most recently added elements first.
//   Using LIFO, is more intuitive and efficient for these use cases.
//.  In other words, the difference lies in how elements are accessed and removed,
//.  making std::stack suitable for specific scenarios where LIFO behavior is desired.

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return this->c.begin(); // 'c' is a protected member of std::stack
			// protected:
			//     Container c;
			// where Container is the type of the underlying container (e.g., std::deque<T> by default).
			// This allows us to use the standard container's iterators directly.
			// For example, we can do this:
			//   MutantStack<int>::iterator it = mstack.begin();
			//   while (it != mstack.end()) {
			//       std::cout << *it << std::endl;
			//       ++it;
			//   }
			// This will iterate through all elements in the MutantStack.
			// Note: We use 'this->c' to access the underlying container because 'c' is a member of the base class std::stack.
			// Using 'this->' is necessary in templates to avoid dependent name issues.
			// This is a common technique when extending standard library containers.
			// More info: https://en.cppreference.com/w/cpp/container/stack
		}

		iterator end()
		{
			return this->c.end();
		}

		reverse_iterator rbegin()
		{
			return this->c.rbegin();
		}

		reverse_iterator rend()
		{
			return this->c.rend();
		}

		const_iterator cbegin() const
		{
			return this->c.begin();
		}

		const_iterator cend() const
		{
			return this->c.end();
		}

		const_reverse_iterator crbegin() const
		{
			return this->c.rbegin();
		}

		const_reverse_iterator crend() const
		{
			return this->c.rend();
		}

		MutantStack& operator=(const MutantStack& other)
		{
			std::stack<T>::operator=(other);
			return *this;
		}

		MutantStack() {}

		MutantStack(const MutantStack& other)
		{
			*this = other;
		}

		~MutantStack() {}
};

#endif