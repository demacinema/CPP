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

// Container Type Helper
template <typename Container>
std::string getContainer();

template <>
std::string getContainer<std::vector<int> >()
{ return "vector<int>"; }

template <>
std::string getContainer<std::deque<int> >()
{ return "deque<int>"; }


// Constructor that initializes the container with values from command-line arguments
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


// Main sorting function implementing the Ford-Johnson sorting algorithm
template <typename Container>
void    PmergeMe<Container>::main_sort()
{
    if (_data.size() == 1)
    {
        _time = 0;
        return ;
    }
    std::clock_t start = std::clock();

    // Step 1: Create and sort pairs
    typedef std::pair<int, int> type_pair;
    std::vector<type_pair> pair_array = this->mergesort_pairs();

    // Step 2: Generate Jacobsthal sequence for insertion order
    std::vector<int> j_index = jacobsthal_sequence(_data.size());

    // Step 3: Sort pair by winner elements
    this->insertsort_pairs(pair_array);

    // Step 4: Merge pairs using insertion sort guided by Jacobsthal sequence
    _data.clear();
    _data.push_back(pair_array[0].second); // Insert the first loser element
    for (size_t i = 0; i < pair_array.size(); i++)
        _data.push_back(pair_array[i].first); // Insert all winner elements

    // Step 5: Insert loser elements in the order defined by the Jacobsthal sequence
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

    // Step 6: If there was an unpaired last element, insert it
    if (_last != -1)
    {
        index = binary_search(_last, _data.size() - 1);
        _data.insert(_data.begin() + index, _last);
    }

    // Step 7: Calculate elapsed time
    _time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
}


// Pairing and sorting helpers

// Pairs up elements and sorts each pair (winner, loser)
template <typename Container>
typename std::vector<typename PmergeMe<Container>::type_pair> PmergeMe<Container>::mergesort_pairs()
{
    std::vector<type_pair> pair_array;
    if (_data.size() % 2 != 0)
    {
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


// Insertion sort for sorting pairs based on winner elements
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

// Generates Jacobsthal sequence up to the given size

template <typename Container>
std::vector<int> PmergeMe<Container>::jacobsthal_sequence(size_t size)
{
    std::vector<int> temp_index; // Temporary vector to hold the initial Jacobsthal numbers.
    std::vector<int> j_index;
    temp_index.push_back(0);
    temp_index.push_back(1);
    int temp;

    for (int i = 2; temp_index.back() < (int)size; i++)
    {
        temp_index.push_back(temp_index[i - 1] + (temp_index[i - 2] * 2));
    }

    for (size_t i = 1; i < temp_index.size() - 1; i++)
    {
        j_index.push_back(temp_index[i + 1]);
        temp = temp_index[i + 1];
        while (--temp > temp_index[i])
            j_index.push_back(temp);
    }
    return (j_index);
}

// Utility functions
// Finds the position of a value in the sorted data (_data)
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

// Binary search to find the correct insertion index for a target value up to max_position
template<typename Container>
int PmergeMe<Container>::binary_search(int target, int max_position)
{
    int left = 0;
    int right = max_position;
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

// Getters and Print functions

// Returns the data container
template <typename Container>
Container PmergeMe<Container>::getData()
{ return (_data); }

// Prints the time taken for sorting
template <typename Container>
void    PmergeMe<Container>::getTime()
{
    std::cout << "Time to process a range of " << _data.size() 
    << " elements with std::" << getContainer<Container>()
    << " : " << std::fixed << std::setprecision(5) << _time << " us" << std::endl;
}

// Prints the elements in the data container
template <typename Container>
void PmergeMe<Container>::printData()
{
    for (typename Container::iterator it = _data.begin(); it != _data.end(); it++)
    {
		std::cout << *it << ' ';
	}
    std::cout << std::endl;
}

// Explicit template instantiation for vector<int> and deque<int>
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;