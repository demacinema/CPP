/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:15:57 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 03:40:39 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//INCLUDES
#include "AForm.hpp"

//METHODS
void	AForm::checkGradeForm(const int gradeSign, const int gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
}


//CONSTRUCTORS
AForm::AForm(): _name(""), _gradeSign(150), _gradeExec(150)
{
	_isSigned = false;
}

AForm::AForm(std::string name, std::string target, int gradeSign, int gradeExec): _name(name), _target(target), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	checkGradeForm(_gradeSign, _gradeExec);
	_isSigned = false;
	std::cout << "Parameterized Constructor: " << _name << " " << _target << " " << _isSigned << " " << _gradeSign << " " << _gradeExec << std::endl;
}

AForm::~AForm()
{
	std::cout << getName()  << " destructed " << std::endl;
}

AForm::AForm(const AForm& other): _name(other.getName()), _gradeSign(other.getGradeSign()), _gradeExec(other.getGradeExec())
{
	checkGradeForm(_gradeSign, _gradeExec);
	_isSigned = other.getIsSigned();
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		checkGradeForm(_gradeSign, _gradeExec);
		_isSigned = other.getIsSigned();
	}
	return *this;
}

//GETTERS
std::string	AForm::getName() const
{
	return _name;	
}

bool		AForm::getIsSigned() const
{
	return _isSigned;
}

int		AForm::getGradeSign() const
{
	return _gradeSign;
}


int		AForm::getGradeExec() const
{
	return _gradeExec;
}

std::string AForm::getTarget() const
{
	return _target;
}

//METHODS
void		AForm::beSigned(const Bureaucrat& bureau)
{
	if(bureau.getGrade() <= _gradeSign)
		_isSigned = true;
	else
		throw AForm::GradeNotValidException();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is higher than maximal!";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is lower than minimal!";
}

const char*	AForm::GradeNotValidException::what() const throw()
{
	return "This form needs a higher grade to be signed!";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "This form needs to be signed!";
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	return (os << form.getName() << " current state is "
		   << (form.getIsSigned() ? "SIGNED" : "NOT SIGNED")
		   << " with a sign grade of " << form.getGradeSign()
		   << " and a execution grade of " << form.getGradeExec());
}

void AForm::checkRequirements(const Bureaucrat& executor) const
{
	if (!_isSigned)
	{
		throw AForm::FormNotSignedException();
	}
	else if (executor.getGrade() > _gradeExec)
	{
		throw AForm::GradeNotValidException();
	}
}
