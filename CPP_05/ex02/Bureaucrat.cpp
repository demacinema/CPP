/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:32:59 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 23:01:42 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void Bureaucrat::checkGrade(int grade) const
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat() : _name("Burrocrata"), _grade(150)
{
	checkGrade(_grade);
	std::cout << "Default Constructor: " << _name << " " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	checkGrade(_grade);
	std::cout << "Parameterized Constructor: " << _name << " " << _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bye from Bureaucrat Destructor of " << getName() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade())
{
	checkGrade(_grade);
	std::cout << "Bureaucrat copy constructor activated!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Assignment Operator!" << std::endl;
	if (this != &other)
	{
		checkGrade(other.getGrade());
		// _name = other.getName(); //Const string cannot be assigned
		_grade = other.getGrade();
	}
	
	return *this; // return the current object to allow method chaining
}

// GETTERS
const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// METHODS
void Bureaucrat::decrementGrade() //increases Grade, as 150 is the lowest
{
	checkGrade(_grade + 1); // check with "+ 1" to ensure the grade is within limits
	_grade += 1;
}

void Bureaucrat::incrementGrade() //diminishes Grade, as 1 is the highest
{
	checkGrade(_grade - 1); // check with "- 1" to ensure the grade is within limits
	_grade -= 1;
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() 
					<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " could not execute " << form.getName() << " because " << e.what() << std::endl;
	}
}


// EXCEPTIONS what() - returns a message when an exception is thrown
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is higher than maximal!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is lower than minimal!";
}

// OUTPUT OVERLOAD
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return os << b.getName() << ", " << "bureaucrat grade " << b.getGrade() << ".";
}
