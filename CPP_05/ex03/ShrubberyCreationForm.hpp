/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:31:22 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:31:36 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {
	private:
		ShrubberyCreationForm();
		static const int _scSignGrade = 145;
		static const int _scExecGrade = 137;

	public:
		void execute(const Bureaucrat& executor) const;

		class FailToOpenFileException : public std::exception {
			public:
				const char* what() const throw();
		};

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};

#endif // __SHRUBBERYCREATIONFORM_H__