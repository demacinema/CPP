/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:38:12 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/12 00:37:16 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	// std::cout << "Hello from Brain Constructor" << std::endl;
	std::cout << "CONSTRUCTING BRAIN..." << std::endl;
}

Brain::~Brain()
{
	// std::cout << "Bye from Brain Destructor" << std::endl;
	std::cout << "DESTRUCTING BRAIN..." << std::endl;
}

Brain::Brain(const Brain& copy_const)
{
	// std::cout << "Hello from Brain copy Constructor" << std::endl;
	std::cout << "COPY CONSTRUCTING BRAIN..." << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = copy_const.ideas[i];
}

Brain& Brain::operator=(const Brain& assign_op)
{
	// std::cout << "Hello from Brain assignment operator" << std::endl;
	std::cout << "ASSIGNMENT OPERATOR BRAIN..." << std::endl;
	if (this != &assign_op)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = assign_op.ideas[i];
	}
	return (*this);
}

