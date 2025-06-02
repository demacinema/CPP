/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:33:07 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/03 01:11:21 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		void checkGrade(int grade) const;

	public:
		Bureaucrat(); // Default Constructor
		Bureaucrat(std::string name, int grade); // Parameterized Constructor
		~Bureaucrat(); // Destructor
		
		Bureaucrat(const Bureaucrat& other); // Copy Constructor
		Bureaucrat& operator=(const Bureaucrat& other); // Assignment Operator

	//	GETTERS
		// std::string getName() const;
		int getGrade() const;
		const std::string getName() const;

	//	GRADE MANIPULATORS
		void decrementGrade();
		void incrementGrade();

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
