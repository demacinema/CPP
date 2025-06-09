
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:12:26 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 22:52:17 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm(){} // NOT NEEDED, BECAUSE THE DEFAULT CONSTRUCTOR IS PRIVATE, SO IT CAN'T BE CALLED

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, _ppSignGrade, _ppExecGrade){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	checkRequirements(executor);

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const char* PresidentialPardonForm::FailToOpenException::what() const throw()
{
	return "The file failed to open or to be created!";
}
