/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:14:53 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/08 20:17:08 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		AForm* makeForm(std::string formName, std::string target);
		
		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
};

#endif