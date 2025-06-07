/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:27:39 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:27:41 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
#define __INTERN_H__

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Form* makeForm(std::string formName, std::string target);
		
		class CannotFindMatchingFormException : public std::exception {
			public:
				const char* what() const throw();
		};

		Intern& operator=(const Intern& other);
		Intern();
		Intern(const Intern& other);
		~Intern();
};

#endif // __INTERN_H__