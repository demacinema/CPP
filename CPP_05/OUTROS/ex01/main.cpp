/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:51:59 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/07 04:07:02 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	Bureaucrat b1("Demetrio Rodrigues", 1);
	Bureaucrat b2("James Bond", 2);
	Bureaucrat b3("Charlize Theron", 50);
	Bureaucrat b4("Xi Jin Ping", 120);
	Bureaucrat b5("Donald Trump", 149);

std::cin.get();
	Form f1("Antrax", 2, 1); //nome, sign grade, exec grade
	Form f2("Plutonio", 1, 1);
	Form f3("Wasser", 119, 150);
	Form f4("Clouds", 30, 50);
	Form f5("Monkey", 120, 3);

std::cin.get();
	try //TESTE TO CREATE FORM LOWER GRADE THAN 150
	{
		Form plutonio("Plutonio", 150, 1445);
		std::cout << plutonio << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

std::cin.get();
	try //TEST TO CREATE FORM HIGHER GRADE THAN 1
	{
		Form pausa("pausa", 1, 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

std::cin.get();
	// TEST TO SIGN FORM WITH BUREAUCRAT HIGHER GRADE THAN FORM SIGN GRADE
	b1.signForm(f1);
	std::cout << b1 << std::endl << f1 << std::endl;
	
std::cin.get();
	// TEST TO SIGN FORM WITH BUREAUCRAT LOWER GRADE THAN FORM SIGN GRADE
	b4.signForm(f3);
	std::cout << b4 << std::endl << f3 << std::endl;

std::cin.get();
	// TEST TO INCREMENT BUREAUCRAT GRADE HIGHER THAN 1
	try
	{
		b1.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

std::cin.get();
	// TEST TO DECREMENT BUREAUCRAT GRADE LOWER THAN 150
	try
	{
		std::cout << b5 << std::endl;
		b5.decrementGrade();
		std::cout << b5 << std::endl;
		b5.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

std::cin.get();
	std::cout << f4 << std::endl;
	f4.beSigned(b2);
	Form assignmentcopy = f4;
	std::cout << assignmentcopy << std::endl;

std::cin.get();
	std::cout << f5 << std::endl;
	f5.beSigned(b1);
	Form copia(f5);
	std::cout << copia << std::endl << std::endl;
}