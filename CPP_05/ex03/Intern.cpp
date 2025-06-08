/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:14:23 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/08 20:37:25 by demrodri         ###   ########.fr       */
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