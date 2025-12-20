/* demrodri@student.42wolfsburg.de
   CPP09 - ex02 - PmergeMe - PmergeMe.cpp */

#include "PmergeMe.hpp"

// Default constructor
template <typename Container>
PmergeMe<Container>::PmergeMe() : _last(-1), _time(0) {}

// Copy constructor
template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other) { *this = other; }

// Destructor
template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

// Assignment operator
template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _data = other._data;
        _last = other._last;
        _time = other._time;
    }
    return *this;
}

template <typename Container>
std::string getContainer();

template <>
std::string getContainer<std::vector<int> >()
{
    return "vector<int>";
}

template <>
std::string getContainer<std::deque<int> >()
{
    return "deque<int>";
}

template <typename Container>
PmergeMe<Container>::PmergeMe(char **argv) : _last(-1), _time(0)
{
    int number;
    for (int i = 0; argv[i]; i++)
    {
        std::istringstream iss(argv[i]);
        iss >> number;
        _data.push_back(number);
    }
}

template <typename Container>
void    PmergeMe<Container>::main_sort()
{
    if (_data.size() == 1)
    {
        // std::cout << "Nothing to sort" << std::endl;
        _time = 0;
        return ;
    }
    std::clock_t start = std::clock();
    typedef std::pair<int, int> type_pair;
    std::vector<type_pair> pair_array = this->mergesort_pairs();
    std::vector<int> j_index = jacobsthal_sequence(_data.size());
    this->insertsort_pairs(pair_array);
    _data.clear();
    _data.push_back(pair_array[0].second);
    for (size_t i = 0; i < pair_array.size(); i++)
        _data.push_back(pair_array[i].first);
    int index = 0;
    for (size_t i = 0; i < j_index.size(); i++)
    {
        if (size_t(j_index[i]) >= pair_array.size())
            continue;

        int loser = pair_array[j_index[i]].second;
        int winner = pair_array[j_index[i]].first;
        int winner_pos = find_position(winner);  // ← Find where winner is

        int search_limit;
        if (winner_pos > 0)
            search_limit = winner_pos - 1;
        else
            search_limit = 0;
        
        index = binary_search(loser, search_limit);  // ← Search only up to winner!
        _data.insert(_data.begin() + index, loser);
    }

    if (_last != -1)
    {
        // 
        index = binary_search(_last, _data.size() - 1);
        _data.insert(_data.begin() + index, _last);
    }
    _time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
}

template <typename Container>
typename std::vector<typename PmergeMe<Container>::type_pair> PmergeMe<Container>::mergesort_pairs()
{
    std::vector<type_pair> pair_array;
    if (_data.size() % 2 != 0){
        _last = _data.back();
        _data.pop_back();
    }
    else
        _last = -1;
    for (size_t i = 0; i < _data.size(); i += 2)
    {
        if (_data[i] < _data[i + 1])
            std::swap(_data[i], _data[i + 1]);
        pair_array.push_back(std::make_pair(_data[i], _data[i + 1]));
    }
    return (pair_array);
}

template <typename Container>
void PmergeMe<Container>::insertsort_pairs(std::vector<type_pair> &pair_array)
{
    if (pair_array.size() == 1)
        return ;
    for (size_t i = 1; i < pair_array.size(); i++)
    {
        type_pair tmp = pair_array[i];
        size_t j = i;
        while (j > 0 && pair_array[j - 1].first > tmp.first){
            pair_array[j] = pair_array[j - 1];
            j--;
        }
        pair_array[j] = tmp;
    }
}


// This function generates the Jacobsthal sequence up to a specified size.
// Without the Jacobsthal sequence, the Ford-Johnson sorting algorithm would not be able to determine the optimal order of insertion during the merging process, potentially leading to less efficient sorting performance.
// For example, if I want to sort (54, 26, 93, 17, 77, 31, 44, 55, 20), the Jacobsthal sequence helps to determine the order in which elements are inserted during the merging process, the pair will be (54,26), (93,17), (77,31), (44,55), (20).
// After sorting each pair, we get (26,54), (17,93), (31,77), (44,55), (20).
// Then, we proceed to merge these pairs using insertion sort guided by the Jacobsthal sequence. Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time.
// Using the Jacobsthal sequence, we can determine the order of insertion during the merging process,
// so the first element to be inserted might be the second element of the second pair (26), followed by the first element of the third pair (17), because the Jacobsthal sequence generated is [1, 3, 5, 11, ...].
// This is how it works, step by step and in a simple explanation:
// 1. It starts by initializing a temporary vector (temp_index) with the first two Jacobsthal numbers: 0 and 1.
// 2. It then enters a loop where it calculates subsequent Jacobsthal numbers using the formula J(n) = J(n-1) + 2 * J(n-2).
// 3. This loop continues until the last calculated Jacobsthal number is less than the specified size.
// 4. After generating the full sequence, it constructs the final Jacobsthal sequence (j_index) by iterating through the temporary vector.
// 5. For each Jacobsthal number in the temporary vector (except the first two), it adds the number to the final sequence and then adds all numbers between the current and the previous Jacobsthal number in descending order.
// 6. Finally, it returns the constructed Jacobsthal sequence. 

template <typename Container>
std::vector<int> PmergeMe<Container>::jacobsthal_sequence(size_t size)
{
    std::vector<int> temp_index; // Temporary vector to store Jacobsthal numbers.
    std::vector<int> j_index; // Final Jacobsthal sequence to be returned.
    temp_index.push_back(0); // this is the first Jacobsthal number, J(0) = 0. It serves as the starting point for generating the sequence.
    temp_index.push_back(1); // this is the second Jacobsthal number, J(1) = 1. It is the next number in the sequence and is used in the calculation of subsequent numbers.

    int temp; // Temporary variable to hold the current Jacobsthal number during the construction of the final sequence.

    for (int i = 2; temp_index.back() < (int)size; i++) // Loop to generate Jacobsthal numbers until the last number is less than the specified size.
    {
        temp_index.push_back(temp_index[i - 1] + (temp_index[i - 2] * 2)); // Calculate the next Jacobsthal number using the formula J(n) = J(n-1) + 2 * J(n-2) and add it to the temporary vector.
    }

    for (size_t i = 1; i < temp_index.size() - 1; i++) // Loop to construct the final Jacobsthal sequence.
    {
        j_index.push_back(temp_index[i + 1]); // Add the current Jacobsthal number to the final sequence.
        temp = temp_index[i + 1]; // Set the temporary variable to the current Jacobsthal number.
        while (--temp > temp_index[i]) // Add all numbers between the current and the previous Jacobsthal number in descending order.
            j_index.push_back(temp); // This ensures that all numbers between the two Jacobsthal numbers are included in the final sequence.
    }
    return (j_index); // Return the constructed Jacobsthal sequence.
}

template<typename Container>
int PmergeMe<Container>::find_position(int value)
{
    for (size_t i = 0; i < _data.size(); i++)
    {
        if (_data[i] == value)
            return i;
    }
    return _data.size() - 1;
}

template<typename Container>
int PmergeMe<Container>::binary_search(int target, int max_position)
{
    int left = 0;
    int right = max_position;  // ← Only search up to here!
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (_data[middle] == target)
            return middle;
        if (_data[middle] > target)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return (left);
}
// template<typename Container>
// int PmergeMe<Container>::binary_search(int target)
// {
//     int left = 0;
//     int right = _data.size() - 1;
//     while (left <= right)
//     {
//         int middle = (left + right) / 2;
//         if (_data[middle] == target)
//             return middle;
//         if (_data[middle] > target)
//             right = middle - 1;
//         else
//             left = middle + 1;
//     }
//     return (left);
// }

template <typename Container>
Container PmergeMe<Container>::getData()
{
    return (_data);
}

template <typename Container>
void    PmergeMe<Container>::getTime()
{
    std::cout << "Time to process a range of " << _data.size() << " elements with std::"
    << getContainer<Container>() << " : " << std::fixed << std::setprecision(5) << _time << " us" << std::endl;
}

template <typename Container>
void PmergeMe<Container>::printData()
{
    for (typename Container::iterator it = _data.begin(); it != _data.end(); it++)
    {
		std::cout << *it << ' ';
	}
    std::cout << std::endl;
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;