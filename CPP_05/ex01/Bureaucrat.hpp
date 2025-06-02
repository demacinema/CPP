/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:53:36 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/03 01:48:06 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form; // include forward declaration to avoid circular dependency: it is needed to declare the Form class before using it in Bureaucrat

class Bureaucrat
{
	private:
		Bureaucrat(); // Default Constructor, now as private to prevent instantiation without parameters
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(std::string name, int grade); // Parameterized Constructor
		~Bureaucrat(); // Destructor

		Bureaucrat(const Bureaucrat& other); // Copy Constructor
		Bureaucrat& operator=(const Bureaucrat& other); // Assignment Operator
	
	//	GETTERS
		std::string getName() const;
		int getGrade() const;
		
	// 	GRADE CHECKER
		void signForm(Form& form) const;

	// GRADE MANIPULATORS
		void decrementGrade();
		void incrementGrade();

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
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif