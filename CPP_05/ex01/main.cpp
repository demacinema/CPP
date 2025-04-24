/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:17:57 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/23 23:28:37 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
	Bureaucrat kafka("kafka", 10);
	Form sellAPPL("sellAPPL", 9, 9);

	try {
		Form buyAPPL("buyAPPL", 151, 1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form holdAPPL("holdAPPL", -1, 150);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << kafka << std::endl;
	std::cout << sellAPPL << std::endl;

	kafka.signForm(sellAPPL);
	std::cout << sellAPPL << std::endl;
	try {
		kafka.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << kafka << std::endl;
	kafka.signForm(sellAPPL);
	std::cout << sellAPPL << std::endl;

	Form normalcopy = sellAPPL;
	Form copy2(sellAPPL);
	std::cout << normalcopy << std::endl;
	std::cout << copy2 << std::endl;
}