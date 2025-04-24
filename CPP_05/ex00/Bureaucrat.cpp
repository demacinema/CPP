/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:32:59 by demrodri          #+#    #+#             */
/*   Updated: 2025/04/24 17:47:43 by demrodri         ###   ########.fr       */
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
	std::cout << "Default Constructor: " << _name << " " << _grade << std::endl;
	checkGrade(_grade);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Parameterized Constructor: " << _name << " " << _grade << std::endl;
	checkGrade(_grade);
	// QUANDO INICIALIZA COM PARAMETROS, JÁ CHECA!
	// if (_grade > 150)
	// {
	// 	throw GradeTooLowException();
	// }
	// else if (grade < 1)
	// {
	// 	throw GradeTooHighException();		
	// }
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bye from Bureaucrat Destructor of " << getName() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade())
{
	std::cout << "Bureaucrat copy constructor activated!" << std::endl;
	checkGrade(_grade);
	// _name = other.getName(); //cant do this as _name is const
	// _grade = other.getGrade();
	// *this = other; //cant do this as _name is const and must be initialized when constructed
                      //this would use the assignment operator, which will not copy values of const variables
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Assignment Operator!" << std::endl;
	if (this != &other) // Avoid self-assignment 
	{
		// _name = other.getName(); //Const string cannot be assigned
		_grade = other.getGrade();
		checkGrade(_grade);
	}
	
	// if (this != &other)
	// {
	// 	*(const_cast<std::string*>(&_name)) = other.getName();
	// 	_grade = other.getGrade();
	// }
	
	return *this; // return the current object to allow method chaining
}

// GETTERS
// std::string Bureaucrat::getName() const
const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// GRADE MANIPULATORS
void Bureaucrat::decrementGrade() //increases Grade, as 150 is the lowest
{
	// if (_grade + 1 > 150) //OR _grade = 150
	// 	throw GradeTooLowException();
	checkGrade(_grade + 1);
	_grade += 1;
}

void Bureaucrat::incrementGrade() //diminishes Grade, as 1 is the highest
{
	// if (_grade - 1 < 1) //OR _grade = 1
	// 	throw GradeTooHighException();
	checkGrade(_grade - 1);
	_grade -= 1;
}

// EXCEPTIONS
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "TOO HIGH GRADE!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "TOO LOW GRADE!";
}

// OUTPUT OVERLOAD
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return os << b.getName() << ", " << "bureaucrat grade " << b.getGrade() << ".";
}
