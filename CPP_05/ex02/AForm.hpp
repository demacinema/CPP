/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:52:46 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 22:46:53 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//DEFINES
#ifndef AFORM_HPP
# define AFORM_HPP

//INCLUDES
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

//PRELOAD
class Bureaucrat;

//CREATE
class AForm
{
	private:
	//CONSTRUCTORS
		AForm();

	//ATTRIBUTES
		const	std::string _name;
		std::string _target;
		bool	_isSigned;
		const	int _gradeSign;
		const	int _gradeExec;

	public:
	//CONTRUCTORS
		AForm(std::string name, std::string target, int gradeSign, int gradeExec);
		virtual ~AForm(); //SO WHEN DELETE A DERIVED OBJECT THROUGH A BASE CLASS POINTER,
						// THE DERIVED CLASS DESTRUCTOR IS CALLED. IF NOT SO, ONLY THE BASE
						// DESTRUCTOR RUNS, AND THE DERIVED CLASS CLEANUP IS SKIPPED.


	//COPY CONSTRUCTORS
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

	//GETTERS
		std::string	getName() const;
		bool		getIsSigned() const;
		int		getGradeSign() const;
		int		getGradeExec() const;
		std::string getTarget() const;

	//METHODS
		void		beSigned(const Bureaucrat& bureau);
		void		checkGradeForm(const int gradeSign, const int gradeExec); //Checks grades are valid, between 1 and 150, inclusive.
		void		checkRequirements(const Bureaucrat& executor) const; //Checks if form is signed and if bureaucrat exec grade is high enough.

	//VIRTUAL FUNCTION TO MAKE IT ABSTRACT
		virtual void execute(const Bureaucrat& executor) const = 0;

	// THE PRETTIER WAY
		// void executeForm(const Bureaucrat& executor) const; // Calls form.execute(executor), and handles exceptions
		// virtual doExecute(const Bureaucrat& executor) const = 0; // Pure virtual function to be implemented by derived classes
	
	//EXCEPTIONS
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeNotValidException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

//OUTPUT OVERLOAD
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
