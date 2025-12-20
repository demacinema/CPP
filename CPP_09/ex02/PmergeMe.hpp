/* demrodri@student.42wolfsburg.de
   CPP09 - ex02 - PmergeMe - PmergeMe.hpp */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstring>
# include <climits>
# include <cstdlib>
# include <sstream>
# include <deque>
# include <ctime>
# include <iomanip>


template <typename Container> // Template class for different container types. This line declares the template, that is a blueprint for creating classes with different container types. E.g.: 
class PmergeMe
{
	private:
		Container	_data;
		int			_last;
		double		_time;
		typedef std::pair<int, int> type_pair;

	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other);

		void		main_sort();

		std::vector<type_pair>	mergesort_pairs();

		void					insertsort_pairs(std::vector<type_pair> &pair_array);

		std::vector<int> jacobsthal_sequence(size_t size); // Generates Jacobsthal sequence up to the given size. Jacobsthal numbers are used to determine the order of insertion during the sorting process. 
		// that is how it works: It starts with the first two Jacobsthal numbers (0 and 1) and iteratively computes subsequent numbers using the formula J(n) = J(n-1) + 2 * J(n-2) until the last number is less than the specified size.
		// The resulting sequence is then used to guide the insertion of elements during the sorting process, optimizing the order in which elements are inserted into the sorted container.
		// In a simpler and more detailed way: Step 1 - Initialize the first two Jacobsthal numbers (0 and 1).
		// Step 2 - Iteratively compute subsequent Jacobsthal numbers using the formula J(n) = J(n-1) + 2 * J(n-2) until the last number is less than the specified size.
		// Step 3 - Store the computed Jacobsthal numbers in a vector and return it.
		// This sequence is then used to guide the insertion of elements during the sorting process.
		// In other words, it helps determine the order in which elements are inserted into the sorted container, optimizing the sorting process.
		// It relates to the Ford-Johnson sorting algorithm, in the way that is explained below:
		// The Ford-Johnson sorting algorithm, also known as the Merge-Insertion sort, is a comparison-based sorting algorithm that combines elements of merge sort and insertion sort.
		// The algorithm works by first dividing the input into pairs of elements, sorting each pair
		// and then merging the sorted pairs using an insertion strategy guided by the Jacobsthal sequence.
		// The Jacobsthal sequence helps determine the order in which elements are inserted during the merging process, optimizing the overall sorting efficiency.
		// For example, if the number to be sorted are [34, 7, 23, 32, 5, 62], the algorithm would first create pairs: (34, 7), (23, 32), (5, 62).
		// Then, it would sort each pair to get: (7, 34), (23, 32), (5, 62).
		// Next, it would use the Jacobsthal sequence to determine the order of insertion, in this case: first inserting 23 (as it is the second element of the second pair),
		// then 5 (first element of the third pair), and so on, until all elements are merged into a single sorted list.
		// A more detailed explanation of how this work, step by step:
		// 1. Pairing: The input list is divided into pairs of elements.
		// 2. Sorting Pairs: Each pair is sorted individually.
		// 3. Merging with Insertion: The sorted pairs are merged together using an insertion strategy guided by the Jacobsthal sequence.
		// In our example: The pairs (7, 34), (23, 32), and (5, 62) are merged together by inserting elements in the order determined by the Jacobsthal sequence, and that order is explained below:
		// Jacobsthal Sequence: The Jacobsthal sequence is generated up to the size of the input list. This sequence helps determine the order of insertion during the merging process.
		// Let's say the Jacobsthal sequence generated is [1, 3, 5, 11, ...].
		// Insertion Order: Using the Jacobsthal sequence, elements are inserted into the sorted list in a specific order. For example, the first element to be inserted might be the second element of the second pair (23),
		// followed by the first element of the third pair (5), and so on.
		// Final Sorted List: After all elements have been inserted

		// int			binary_search(int target);
		int binary_search(int target, int max_position);
		int find_position(int value);

		Container	getData();
		void		getTime();
		void		printData();
};

#endif