/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:39:38 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:39:39 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Hello from Brain Constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Bye from Brain Destructor" << std::endl;
}

Brain::Brain(const Brain& copy_const)
{
	std::cout << "Hello from Brain copy Constructor" << std::endl;
	*this = copy_const; 
}

Brain& Brain::operator=(const Brain& assign_op)
{
	std::cout << "Hello from Brain assignment operator" << std::endl;
	if (this != &assign_op)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = assign_op.ideas[i];
	}
	return (*this);
}

