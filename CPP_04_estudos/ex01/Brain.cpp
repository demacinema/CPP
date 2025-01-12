/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:32:52 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/12 00:07:16 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "CONSTRUCTING BRAIN..." << std::endl;
}

// Brain::Brain(const std::string& name) : Brain(name)
// {
	
// 	std::cout << "STRING CONSTRUCTING BRAIN..." << std::endl;	
// }

Brain::~Brain()
{
	std::cout << "DESTRUCTING BRAIN..." << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "COPY CONSTRUCTING BRAIN..." << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "ASSIGNMENT OPERATOR BRAIN..." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}