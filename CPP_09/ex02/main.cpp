/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:50:54 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:55:00 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	dup_handle(char **argv)

{
	for (int i = 1; argv[i]; i++)
	{
		for (int j = i + 1; argv[j]; j++)
		{
			if (strcmp(argv[i], argv[j]) == 0)
				return (1);
		}
	}
	return (0);
}

int	symbol_handle(char **argv)

{
	for (int i = 1; argv[i]; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (isdigit(argv[i][j]) == 0)
				return (1);
		}
	}
	return (0);
}

int	int_handle(char **argv)

{
    char *endptr;
	for (int i = 1; argv[i]; i++)
	{
		if (std::strtoul(argv[i], &endptr, 10) < 0 || std::strtoul(argv[i], &endptr, 10) > UINT_MAX)
			return (1);
	}
	return (0);
}

void	error_handle(char **argv)
{
	if (int_handle(argv))
		std::cerr << "UINT limit reached!" << std::endl;
	else if (dup_handle(argv))
		std::cerr << "Duplicates exist!" << std::endl;
	else if (symbol_handle(argv))
		std::cerr << "Wrong symbols exist!" << std::endl;
	else
		return ;
	exit(1);
}

int main(int argc, char **argv){
    if (argc < 2)
    {
        std::cerr << "No arguments given!" << std::endl;
        return (1);
    }
    error_handle(argv);
	PmergeMe<std::vector<int> > vector(argv + 1);
	PmergeMe<std::deque<int> > deque(argv + 1);
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