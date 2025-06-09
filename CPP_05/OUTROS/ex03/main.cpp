/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:35:07 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/08 20:40:37 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

// void test()
int main()
{
	Bureaucrat lula("Lula", 5);
	Intern someIntern;

	AForm* shrubbery = someIntern.makeForm("shrubbery creation", "tree");
	AForm* robotomy = someIntern.makeForm("robotomy request", "robo");
	AForm* presidential = someIntern.makeForm("presidential pardon", "lula");
	someIntern.makeForm("makeMoney request", "lula");

	std::cout << lula << std::endl;
	std::cout << std::endl;

	std::cout << *shrubbery << std::endl;
	lula.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl;
	lula.executeForm(*shrubbery);
	std::cout << std::endl;

	std::cout << *robotomy << std::endl;
	lula.signForm(*robotomy);
	std::cout << *robotomy << std::endl;
	lula.executeForm(*robotomy);
	std::cout << std::endl;

	std::cout << *presidential << std::endl;
	lula.signForm(*presidential);
	std::cout << *presidential << std::endl;
	lula.executeForm(*presidential);
	std::cout << std::endl;

std::cin.get();

	Intern  someRandomIntern;
	AForm*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;

std::cin.get();
	
	delete shrubbery;
	delete robotomy;
	delete presidential;
}

// int main()
// {
// 	test();
// 	system("leaks form");
// }