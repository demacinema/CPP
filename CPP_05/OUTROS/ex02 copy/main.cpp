/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:23:10 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/23 23:16:23 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat kafka("kafka", 1);
	Form* shrubbery = new ShrubberyCreationForm("GAEPO");
	Form* robotomy = new RobotomyRequestForm("GEAPO");
	Form* pp = new PresidentialPardonForm("kafka");

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