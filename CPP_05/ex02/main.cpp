/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:51:59 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/08 16:20:07 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
// std::cin.get();

	Bureaucrat merz("Merz", 1);   //TEST BUREAU CAN SIGN AND EXECUTE
	// Bureaucrat merz("Merz", 142); //TEST BUREAU CAN SIGN BUT NOT EXECUTE
	// Bureaucrat merz("Merz", 150); //TEST BUREU CAN'T SIGN NOR EXECUTE

	AForm* shrubbery = new ShrubberyCreationForm("tree");
	std::cout << *shrubbery << std::endl << std::endl;
	
	merz.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl << std::endl;
	
	merz.executeForm(*shrubbery);
	std::cout << std::endl;

std::cin.get();	

	AForm* robotomy = new RobotomyRequestForm("robot");
	std::cout << *robotomy << std::endl << std::endl;
std::cin.get();
	merz.signForm(*robotomy);
	std::cout << *robotomy << std::endl << std::endl;
	
std::cin.get();
	merz.executeForm(*robotomy);
	std::cout << "1" << std::endl;
std::cin.get();
	merz.executeForm(*robotomy);
	std::cout << "2" << std::endl;
std::cin.get();
	merz.executeForm(*robotomy);
	std::cout << "3" << std::endl;
std::cin.get();
	merz.executeForm(*robotomy);
	std::cout << "4" << std::endl;

std::cin.get();

	AForm* presidential = new PresidentialPardonForm("Presida");
	std::cout << *presidential << std::endl << std::endl;

	merz.signForm(*presidential);
	std::cout << *presidential << std::endl << std::endl;
	
	merz.executeForm(*presidential);
	std::cout << *presidential << std::endl << std::endl;
	
	delete presidential;
	delete robotomy;
	delete shrubbery;
}
