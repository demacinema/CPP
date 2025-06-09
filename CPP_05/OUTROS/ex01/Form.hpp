/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:16:11 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 03:12:02 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//DEFINES
#ifndef FORM_HPP
# define FORM_HPP

//INCLUDES
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

//PRELOAD
class Bureaucrat;

//CREATE
class Form
{
	private:
	//CONSTRUCTORS
		Form();

	//ATTRIBUTES
		const	std::string _name;
		bool	_isSigned;
		const	int _gradeSign;
		const	int _gradeExec;

	public:
	//CONTRUCTORS
		Form(std::string name, int gradeSign, int gradeExec);
		~Form();


	//COPY CONSTRUCTORS
		Form(const Form& other);
		Form& operator=(const Form& other);

	//GETTERS
		std::string	getName() const;
		bool		getIsSigned() const;
		int		getGradeSign() const;
		int		getGradeExec() const;

	//MANIPULATIVE METHODS
		void		beSigned(const Bureaucrat& bureau);
		void		checkGradeForm(const int gradeSign, const int gradeExec);
		
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
};

//OUTPUT OVERLOAD
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
