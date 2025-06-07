/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:51:59 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 22:58:27 by demrodri         ###   ########.fr       */
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

	delete shrubbery;
}