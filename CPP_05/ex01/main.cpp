/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:17:57 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:17:59 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
	Bureaucrat jaemjung("jaemjung", 10);
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

	std::cout << jaemjung << std::endl;
	std::cout << sellAPPL << std::endl;

	jaemjung.signForm(sellAPPL);
	std::cout << sellAPPL << std::endl;
	try {
		jaemjung.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << jaemjung << std::endl;
	jaemjung.signForm(sellAPPL);
	std::cout << sellAPPL << std::endl;

	Form copy = sellAPPL;
	Form copy2(sellAPPL);
	std::cout << copy << std::endl;
	std::cout << copy2 << std::endl;
}