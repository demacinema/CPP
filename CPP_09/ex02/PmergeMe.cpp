/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:50:57 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:55:21 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
std::string getContainer();

template <>
std::string getContainer<std::vector<int> >(){
    return "vector<int>";
}

template <>
std::string getContainer<std::deque<int> >(){
    return "deque<int>";
}


template <typename Container>
PmergeMe<Container>::PmergeMe(char **argv){
    int number;
    for (int i = 0; argv[i]; i++){
        std::istringstream iss(argv[i]);
        iss >> number;
        _data.push_back(number);
    }
}

template <typename Container>
void    PmergeMe<Container>::main_sort(){
    if (_data.size() == 1){
        std::cout << "Nothing to sort" << std::endl;
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
    for (size_t i = 0; i < j_index.size(); i++){
        if (size_t(j_index[i]) >= pair_array.size())
            continue;
        index = binary_search(pair_array[j_index[i]].second);
        _data.insert(_data.begin() + index, pair_array[j_index[i]].second);
    }
    if (_last != -1){
        index = binary_search(_last);
        _data.insert(_data.begin() + index, _last);
    }
    _time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
}

template <typename Container>
typename std::vector<typename PmergeMe<Container>::type_pair> PmergeMe<Container>::mergesort_pairs(){
    std::vector<type_pair> pair_array;
    if (_data.size() % 2 != 0){
        _last = _data.back();
        _data.pop_back();
    }
    else
        _last = -1;
    for (size_t i = 0; i < _data.size(); i += 2){
        if (_data[i] < _data[i + 1])
            std::swap(_data[i], _data[i + 1]);
        pair_array.push_back(std::make_pair(_data[i], _data[i + 1]));
    }
    return (pair_array);
}

template <typename Container>
void PmergeMe<Container>::insertsort_pairs(std::vector<type_pair> &pair_array){
    if (pair_array.size() == 1)
        return ;
    for (size_t i = 1; i < pair_array.size(); i++){
        type_pair tmp = pair_array[i];
        size_t j = i;
        while (j > 0 && pair_array[j - 1].first > tmp.first){
            pair_array[j] = pair_array[j - 1];
            j--;
        }
        pair_array[j] = tmp;
    }
}

template <typename Container>
std::vector<int> PmergeMe<Container>::jacobsthal_sequence(size_t size){
    std::vector<int> temp_index;
    std::vector<int> j_index;
    temp_index.push_back(0);
    temp_index.push_back(1);
    int temp;
    for (int i = 2; temp_index.back() < (int)size; i++){
        temp_index.push_back(temp_index[i - 1] + (temp_index[i - 2] * 2));
    }
    for (size_t i = 1; i < temp_index.size() - 1; i++){
        j_index.push_back(temp_index[i + 1]);
        temp = temp_index[i + 1];
        while (--temp > temp_index[i])
            j_index.push_back(temp);
    }
    return (j_index);
}

template<typename Container>
int PmergeMe<Container>::binary_search(int target){
    int left = 0;
    int right = _data.size() - 1;
    while (left <= right){
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

template <typename Container>
Container PmergeMe<Container>::getData(){
    return (_data);
}

template <typename Container>
void    PmergeMe<Container>::getTime(){
    std::cout << "Time to process a range of " << _data.size() << " elements with std::"
    << getContainer<Container>() << " : " << std::fixed << std::setprecision(6) << _time << " us" << std::endl;
}

template <typename Container>
void PmergeMe<Container>::printData(){
    for (typename Container::iterator it = _data.begin(); it != _data.end(); it++){
		std::cout << *it << ' ';
	}
    std::cout << std::endl;
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;