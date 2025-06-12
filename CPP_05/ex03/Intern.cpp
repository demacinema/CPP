/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:14:23 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/12 15:25:41 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other)
{
	static_cast<void>(other);
}

Intern& Intern::operator=(const Intern& other)
{
	static_cast<void>(other);//USING IT TO COMPILE
	return *this;
}

Intern::~Intern(){}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Intern not able to find this form.";
}

// The difference between the class Bureaucrat and the class Intern is that Bureaucrat is responsible for signing forms, while Intern is responsible for creating them.
// In more details: While the Bureaucrat class is designed to manage the signing and execution of forms, ensuring that the bureaucratic process is followed correctly, the Intern class is focused on creating specific types of forms based on given names and targets.
// The Intern class acts as a factory for form objects, allowing the creation of forms like RobotomyRequestForm, ShrubberyCreationForm, and PresidentialPardonForm based on the form name provided.
// The Intern class does not need to manage the signing or execution of these forms; it simply creates them when requested, making it a specialized component in the bureaucratic system.
// For creating them, the Intern class uses a specific function that takes the form name and target as parameters and returns a new form object.
// Then, this new form object can be used by a Bureaucrat to sign or execute it, following the bureaucratic process defined in the AForm class and its derived classes.
// If there were not a class Intern, the Bureaucrat class would have to handle the creation of forms directly, which would violate the single responsibility principle and make the code less modular and harder to maintain.

// Summarizing, the Intern class is a specialized component that focuses on creating forms, while the Bureaucrat class is responsible for managing the bureaucratic process of signing and executing those forms.

// This function creates a form based on the form name and target provided. This is how it works in a detailed way:
// 1. It defines an array of form names.
// 2. It iterates through the array to check if the provided form name matches any of the predefined names.
// 3. If a match is found, it creates the corresponding form object and returns it.

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNameList[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (formName == formNameList[i])
			{
				std::cout << "Intern creates " << formNameList[i] << " form" << std::endl;
				switch (i)
				{
					case 0:
						return new RobotomyRequestForm(target);
					case 1:
						return new ShrubberyCreationForm(target);
					case 2:
						return new PresidentialPardonForm(target);
				}
			}
		}
		throw Intern::FormNotFoundException();
	}
	catch (Intern::FormNotFoundException& e)
	{
		std::cout << "Intern not able to create form because " << e.what() << std::endl;
	}
	return NULL;
}