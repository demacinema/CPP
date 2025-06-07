/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:51:59 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/03 01:52:03 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	Bureaucrat kafka("kafka", 10);
	Form sellAPPL("sellAPPL", 9, 9);

	try
	{
		Form buyAPPL("buyAPPL", 151, 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form holdAPPL("holdAPPL", -1, 150);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << kafka << std::endl;
	std::cout << sellAPPL << std::endl;

	kafka.signForm(sellAPPL);
	std::cout << sellAPPL << std::endl;
	
	try
	{
		kafka.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << kafka << std::endl;
	kafka.signForm(sellAPPL);
	std::cout << sellAPPL << std::endl;

	Form normalcopy = sellAPPL;
	Form copy2(sellAPPL);
	std::cout << normalcopy << std::endl;
	std::cout << copy2 << std::endl;
}