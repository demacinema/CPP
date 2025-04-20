/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:16:43 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 21:39:51 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "FragTrap.hpp"
// #include "ScavTrap.hpp"

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat jaemjung("jaemjung", 1);
	Bureaucrat w("whoever", 150);

	std::cout << jaemjung << std::endl;
	try {
		std::cout << "try to increment jaemjung's grade." << std::endl;
		jaemjung.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << jaemjung <<std::endl;
	try {
		std::cout << "try to decrement jaemjung's grade." << std::endl;
		jaemjung.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << jaemjung << std::endl;
	Bureaucrat copy(jaemjung);
	Bureaucrat copy2 = jaemjung;
	std::cout << copy << std::endl;
	std::cout << copy2 << std::endl;
	std::cout << std::endl;

	std::cout << w << std::endl;
	try {
		std::cout << "try to decrement whoever's grade." << std::endl;
		w.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << w <<std::endl;
	try {
		std::cout << "try to increment whoever's grade." << std::endl;
		w.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << w << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "try to make Bureaucrat with lower than minimum grade" <<std::endl;
		Bureaucrat someOne("someOne", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "try to make Bureaucrat with lower than maximum grade" <<std::endl;
		Bureaucrat someOne2("someOne2", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	} 
}