/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:27:48 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/23 23:16:23 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void test() {
	Bureaucrat kafka("kafka", 5);
	Intern someIntern;

	Form* shrubbery = someIntern.makeForm("shrubbery creation", "GAEPO");
	Form* robotomy = someIntern.makeForm("robotomy request", "GEAPO");
	Form* pp = someIntern.makeForm("presidential pardon", "kafka");
	someIntern.makeForm("makeMoney request", "kafka");

	std::cout << kafka << std::endl;
	std::cout << std::endl;

	std::cout << *shrubbery << std::endl;
	kafka.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl;
	kafka.executeForm(*shrubbery);
	std::cout << std::endl;

	std::cout << *robotomy << std::endl;
	kafka.signForm(*robotomy);
	std::cout << *robotomy << std::endl;
	kafka.executeForm(*robotomy);
	std::cout << std::endl;

	std::cout << *pp << std::endl;
	kafka.signForm(*pp);
	std::cout << *pp << std::endl;
	kafka.executeForm(*pp);
	std::cout << std::endl;

	delete shrubbery;
	delete robotomy;
	delete pp;
}

int main() {
	test();
	system("leaks form");
}