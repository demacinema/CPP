/* demrodri@student.42wolfsburg.de
   CPP07 - ex02 - array - Array.hpp */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int _size; // Array size
		T* _arr; // Pointer to the array of type T

	public:
		// Getters
		unsigned int size() const // Function to get the size of the array
		{
			return _size;
		}

		T* getArr() const // Function to get the internal array pointer
		{
			return _arr;
		}

		// Exception class for index out of bounds
		class IdxOutOfBounds: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Index out of bounds";
				}
		};

		// Subscript operator overloads
		T& operator[](unsigned int i) const
		{
			if (i >= _size)
			{
				throw IdxOutOfBounds();
			}
			return _arr[i];
		}

		// Assignment operator overload
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				if (_size)
				{
					delete[] _arr;
					_arr = NULL;
					_size = 0;
				}
				_size = other.size();
				if (_size)
				{
					_arr = new T[_size];
					for (unsigned int i = 0; i < _size; i++)
					{
						_arr[i] = other.getArr()[i];
					}
				}
			}
			return *this;
		}

		// Constructors and Destructor
		Array(): _size(0), _arr(NULL) {}

		Array(unsigned int size): _size(size), _arr(NULL)
		{
			if (size > 0)
				_arr = new T[size];
		}

		Array(const Array& other): _size(other.size()), _arr(NULL)
		{
			if (_size)
			{
				_arr = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
				{
					_arr[i] = other.getArr()[i];
				}
			}
		}

		~Array()
		{
			if (_size)
			{
				delete[] _arr;
				_arr = NULL;
			}
		}
};

// Overload of the output stream operator for Array
template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		os << "[ "<< i << " ] : " << arr[i] << std::endl;
	}
	return os;
}

#endif