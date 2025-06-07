/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:12:14 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 23:04:54 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		// ShrubberyCreationForm();
		static const int _shSignGrade = 145; // Var belongs to the class, not to each instance. 
		static const int _shExecGrade = 137; // if not static: error: default member initializer for non-static data member is a C++11 extension

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat& executor) const; // The work! Creates a file with ASCII art trees in the target directory.

		class FailInFileException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif