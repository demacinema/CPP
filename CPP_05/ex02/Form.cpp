/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:15:57 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 03:40:39 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//INCLUDES
#include "Form.hpp"

//METHODS
void	Form::checkGradeForm(const int gradeSign, const int gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}


//CONSTRUCTORS
Form::Form(): _name(""), _gradeSign(150), _gradeExec(150)
{
	_isSigned = false;
}

Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	checkGradeForm(_gradeSign, _gradeExec);
	_isSigned = false;
	std::cout << "Parameterized Constructor: " << _name << " " << _isSigned << " " << _gradeSign << " " << _gradeExec << std::endl;
}

Form::~Form()
{
	std::cout << getName()  << " destructed " << std::endl;
}

Form::Form(const Form& other): _name(other.getName()), _gradeSign(other.getGradeSign()), _gradeExec(other.getGradeExec())
{
	checkGradeForm(_gradeSign, _gradeExec);
	_isSigned = other.getIsSigned();
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		checkGradeForm(_gradeSign, _gradeExec);
		_isSigned = other.getIsSigned();
	}
	return *this;
}

//GETTERS
std::string	Form::getName() const
{
	return _name;	
}

bool		Form::getIsSigned() const
{
	return _isSigned;
}

int		Form::getGradeSign() const
{
	return _gradeSign;
}


int		Form::getGradeExec() const
{
	return _gradeExec;
}

//METHODS
void		Form::beSigned(const Bureaucrat& bureau)
{
	if(bureau.getGrade() <= _gradeSign)
		_isSigned = true;
	else
		throw Form::GradeNotValidException();
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form grade is higher than maximal!";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form grade is lower than minimal!";
}

const char*	Form::GradeNotValidException::what() const throw()
{
	return "this form needs a higher grade to be signed!";
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	return (os << form.getName() << " current state is "
		   << (form.getIsSigned() ? "SIGNED" : "NOT SIGNED")
		   << " with a sign grade of " << form.getGradeSign()
		   << " and a execution grade of " << form.getGradeExec());
}
