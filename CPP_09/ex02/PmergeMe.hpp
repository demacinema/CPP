/* demrodri@student.42wolfsburg.de
   CPP09 - ex02 - PmergeMe - PmergeMe.hpp */

/* 
   Ford-Johnson (Merge-Insertion) Sort:
   - Pairs input, sorts pairs, merges using Jacobsthal sequence for optimal insertion order.
   - Uses two STL containers (vector and deque) for demonstration.
*/

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <cstring>
# include <climits>
# include <cstdlib>
# include <sstream>
# include <deque>
# include <ctime>
# include <iomanip>

// Template class: "blueprint" for creating classes based on different data types or containers.
template <typename Container>
class PmergeMe
{
	private:
		Container	_data; // Container to hold the data (vector or deque).
		int			_last; // Holds the last unpaired element if the size of _data is odd.
		double		_time; // Time taken to perform the sorting.
		typedef std::pair<int, int> type_pair; // Type alias for a pair of integers (winner, loser)

	public:
		PmergeMe();                                  // Default constructor
		PmergeMe(char **argv);                       // Constructor from argv
		PmergeMe(const PmergeMe &other);             // Copy constructor
		~PmergeMe();                                 // Destructor
		PmergeMe &operator=(const PmergeMe &other);  // Assignment operator

		void	main_sort();                         // Main sorting function

		std::vector<type_pair>	mergesort_pairs();                     // Pair and sort elements
		void	insertsort_pairs(std::vector<type_pair> &pair_array);  // Sort pairs by winner elements

		std::vector<int> jacobsthal_sequence(size_t size); 			  // Generate Jacobsthal sequence

		int binary_search(int target, int max_position);             // Binary search for insertion index
		int find_position(int value);                                // Find position of a value in sorted data

		Container	getData();           // Returns the data container
		void		getTime();           // Prints the time taken for sorting
		void		printData();         // Prints the elements in the data container
};

#endif