/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:51:05 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:55:36 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


template <typename Container>
class PmergeMe{
	private:
		Container	_data;
		int			_last;
		double		_time;
		typedef std::pair<int, int> type_pair;

	public:
		PmergeMe(){};
		PmergeMe(char **argv);
		~PmergeMe(){};
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void		main_sort();
		std::vector<type_pair>	mergesort_pairs();
		void					insertsort_pairs(std::vector<type_pair> &pair_array);
		std::vector<int> jacobsthal_sequence(size_t size);
		int			binary_search(int target);
		Container	getData();
		void		getTime();
		void		printData();

	
};

#endif