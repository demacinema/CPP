/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:52:46 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/12 15:25:10 by demrodri         ###   ########.fr       */
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

	// THE PRETTIER WAY: THIS WOULD BE THE WAY TO EXECUTE A FORM, BUT IT IS NOT IMPLEMENTED. IT IS BETTER BECAUSE IT KEEPS THE EXECUTION LOGIC IN THE AForm CLASS, AND NOT IN THE DERIVED CLASSES.
	
		// IT IS ALWAYS A BETTER PRACTICE TO KEEP THE LOGIC IN THE BASE CLASS, AND THE BEHAVIOR IN THE DERIVED CLASSES.
		// LOGIC = CHECKING IF THE FORM IS SIGNED, IF THE BUREAUCRAT HAS THE RIGHT GRADE TO EXECUTE IT, ETC. IT IS COMMON TO ALL FORMS, SO IT SHOULD BE IN THE BASE CLASS.
		// BEHAVIOR = WHAT THE FORM DOES WHEN EXECUTED (E.G., CREATING A SHRUBBERY, PARDONING A PRESIDENT, ETC.). IT IS SPECIFIC TO EACH FORM, SO IT SHOULD BE IN THE DERIVED CLASSES.
		
		// void executeForm(const Bureaucrat& executor) const; // Would check requirements and deal with exceptions, then call the virtual execute function specific for each form.
		// virtual doExecute(const Bureaucrat& executor) const = 0; // Would be the function that does the actual execution of the form, to be implemented by derived classes.
		
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
