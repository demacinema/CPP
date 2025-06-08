/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:24:45 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/08 03:12:26 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// RobotomyRequestForm::RobotomyRequestForm(){} // NOT NEEDED, BECAUSE THE DEFAULT CONSTRUCTOR IS PRIVATE, SO IT CAN'T BE CALLED

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, _rbSignGrade, _rbExecGrade){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){};

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkRequirements(executor);

	std::cout << "DRILLING!!" << std::endl;

	std::srand(static_cast<unsigned int>(time(NULL))); // Seed the starting point with the current time (to ensure different results each time the program runs)
	int rand = std::rand(); // Generate a random number
	
	if (rand % 2) // If the random number is even
	{
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "failed to robotomize " << getTarget() << std::endl;
	}
}

const char* RobotomyRequestForm::FailToOpenException::what() const throw()
{
	return "The file failed to open or to be created!";
}
