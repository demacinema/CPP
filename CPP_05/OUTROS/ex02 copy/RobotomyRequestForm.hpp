/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demetriorodrigues <demetriorodrigues@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:21:05 by demetriorod       #+#    #+#             */
/*   Updated: 2025/04/20 22:21:07 by demetriorod      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form {
	private:
		RobotomyRequestForm();
		static const int _rrSignGrade = 72;
		static const int _rrExecGrade = 45;

	public:
		void execute(const Bureaucrat& executor) const;

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
};

#endif // __ROBOTOMYREQUESTFORM_H__
