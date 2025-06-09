/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:33:07 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 22:37:17 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		Bureaucrat(); // Default Constructor as private, to prevent its use and create a Bureaucrat without name and grade
		const std::string _name;
		int _grade;
		void checkGrade(int grade) const;

	public:
		Bureaucrat(std::string name, int grade); // Parameterized Constructor
		~Bureaucrat(); // Destructor
		
		Bureaucrat(const Bureaucrat& other); // Copy Constructor
		Bureaucrat& operator=(const Bureaucrat& other); // Assignment Operator

	//	GETTERS
		// std::string getName() const;
		int getGrade() const;
		const std::string getName() const;

	//	METHODS
		void decrementGrade();
		void incrementGrade();
		void signForm(AForm& form) const;
		void executeForm(const AForm& form) const;// calls form.execute(*this), and handles exceptions

	//	EXCEPTIONS
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