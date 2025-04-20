/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:39:44 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:39:46 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void display(T &obj) {
	std::cout << obj << std::endl;
}

int main() {
	std::string strs[5] = {"ABCD", "EFGH", "IJKL", "MNOP", "QRST"};
	int ints[5] = {100, 200, 300, 400, 500};
	float floats[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

	iter(strs, 5, display);
	iter(ints, 5, display);
	iter(floats, 5, display);
	return 0;
}