/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:55:06 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 21:23:41 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat merz("Merz", 1);
	Bureaucrat merkel("Merkel", 150);
	// Bureaucrat noparametertest; //not possible, as it is forbidden to create a Bureaucrat without parameters
	// Grade will be checked on the construction by the method checkGrade
	
std::cin.get();
	try
	{
		std::cout << "TEST: GRADE INCREMENT >> " << merz << std::endl;
		merz.incrementGrade();
		std::cout << merz << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();
	try
	{
		std::cout << "TEST: GRADE DECREMENT >> " << merz << std::endl;
		merz.decrementGrade();
		std::cout << merz << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();
	Bureaucrat normalcopy(merz);
	Bureaucrat operatorcopy("maria", 50);
	operatorcopy = normalcopy; //will have the grade of kafka, but not the name (as it is const and can only be set at contruction)
	
	std::cout << normalcopy << std::endl;
	std::cout << operatorcopy << std::endl << std::endl;

std::cin.get();
	std::cout << merkel << std::endl;
	try
	{
		std::cout << "TEST: GRADE DECREMENT >> " << merkel << std::endl;
		merkel.decrementGrade();
		std::cout << merkel << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();	
	try
	{
		std::cout << "TEST: GRADE INCREMENT >> " << merkel << std::endl;
		merkel.incrementGrade();
		std::cout << merkel << std::endl;
	} 
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();
	try
	{
		std::cout << "TEST: LOWER THAN MINIMAL " << std::endl;
		Bureaucrat lower("Lower", 151);
		std::cout << lower << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();
	try
	{
		std::cout << "TEST: BIGGER THAN MAXIMAL " <<std::endl;
		Bureaucrat maximal("Maximal", 0);
		std::cout << maximal << std::endl << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}
	
}

// CHECK IF DESTRUCTORS IS BEHAVING CORRECTLY!!