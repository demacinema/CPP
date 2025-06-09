/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:12:26 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/09 18:23:44 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm(){} // NOT NEEDED, BECAUSE THE DEFAULT CONSTRUCTOR IS PRIVATE, SO IT CAN'T BE CALLED

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, _shSignGrade, _shExecGrade){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	checkRequirements(executor);

	std::ofstream output((this->getTarget() + "_shrubbery").c_str());//CREATE NEW FILE (the .c_str() - converts std::string to const char* - and is because std::ofstream in Linux does not have a constructor that takes string)
	std::ifstream input("shrubbery");//OPEN FILE FOR READING

	std::string line;

	if (!output.is_open() || !input.is_open())//CHECK IF DID NOT WENT WELL (could be done for each try individually)
	{
		throw ShrubberyCreationForm::FailInFileException();
	}

	while (!input.eof())//COPY LINES FROM INPUT TO OUTPUT
	{
		getline(input, line);
		output << line << std::endl;
	}
	input.close();//IF OPEN, NEEDS CLOSE
	output.close();
}

const char* ShrubberyCreationForm::FailInFileException::what() const throw()
{
	return "The file failed to open or to be created!";
}
