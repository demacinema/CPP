/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:44:01 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:44:03 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <iostream>

#include "easyfind.hpp"

template <typename T>
void displayIter(T it, T end) {
	if (it != end) 
		std::cout << "Value of iterator: " << *it << std::endl;
	else
		std::cout << "iterator end" << std::endl;
}

template <typename T>
void findNum(T& container, int toFind) {
	typename T::iterator it;

	try {
		it = easyfind(container, toFind);
		std::cout << "Element [" << toFind << "] found" << std::endl;
	} catch (std::exception &e) {
		it = container.end();
		std::cout << e.what() << std::endl;
	}
	displayIter(it, container.end());
}

int main() {
	std::vector<int> v;
	std::deque<int> d;
	std::list<char> l;

	for (int i = 0; i < 100; i+=3) {
		v.push_back(i);
		d.push_back(i + 1);
		l.push_back(i + 2);
	}

	findNum(v, 33);
	findNum(v, 34);
	findNum(v, 35);

	findNum(d, 33);
	findNum(d, 34);
	findNum(d, 35);

	findNum(l, 33);
	findNum(l, 34);
	findNum(l, 35);
}