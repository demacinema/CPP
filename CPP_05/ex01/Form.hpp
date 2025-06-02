/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:52:32 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/03 01:52:35 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat; // This tells the compiler that the class exists, without needing the full definition, which avoids circular dependencies.

class Form
{
	private:
		Form(); // Default Constructor, now as private to prevent instantiation without parameters
		const std::string _name;
		bool _isSigned;
		const int _gradeSign;
		const int _gradeExecute;
	
	public:
		Form(std::string name, int gradeSign, int gradeExecute); // Parameterized Constructor
		~Form(); // Destructor
		
		Form(const Form& other); // Copy Constructor
		Form& operator=(const Form& other); // Assignment Operator

	//	GETTERS
		std::string getName() const;
		int getSignGrade() const;
		int getExcuteGrade() const;

	//	FORM CHECKER
		bool isSigned() const;

	//  FORM MANIPULATORS
		void beSigned(const Bureaucrat& bc);

	// EXCEPTIONS
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
};

// OUTPUT OVERLOAD
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif