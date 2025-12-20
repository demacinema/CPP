/* demrodri@student.42wolfsburg.de
   CPP09 - ex02 - PmergeMe - main.cpp */

#include "PmergeMe.hpp"

int has_error(char **argv)
{
    char *endptr;
    for (int i = 1; argv[i]; i++)
    {
        // Reject any non-digit characters
        for (int j = 0; argv[i][j]; j++)
            if (!isdigit(argv[i][j]))
                return (1);
        // Reject zero as input
        if (strcmp(argv[i], "0") == 0)
            return (1);
        // Reject numbers larger than INT_MAX
        unsigned long val = std::strtoul(argv[i], &endptr, 10);
        if (val > INT_MAX)
            return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
	// Check for missing arguments
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
	// Check for invalid arguments
    if (has_error(argv))
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
	
	// Create containers and perform sorting
	PmergeMe<std::vector<int> > vector(argv + 1);
	PmergeMe<std::deque<int> > deque(argv + 1);

	// Print results
	std::cout << "Before: ";
	vector.printData();
	vector.main_sort();
	deque.main_sort();
	std::cout << "After: ";
	vector.printData();
	vector.getTime();
	deque.getTime();
	return (0);
}