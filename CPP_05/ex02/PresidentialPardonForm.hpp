/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:57:40 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/09 22:57:44 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
		static const int _ppSignGrade = 25;
		static const int _ppExecGrade = 5;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm (const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void execute(const Bureaucrat& executor) const;

		class FailToOpenException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif