#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
		static const int _rbSignGrade = 72;
		static const int _rbExecGrade = 45;

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void execute(const Bureaucrat& executor) const;

		class FailToOpenException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif