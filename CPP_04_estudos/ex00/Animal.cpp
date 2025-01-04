/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:50:22 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:18:42 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Default constructor of ANIMAL called: " << type << std::endl;
}

Animal::Animal(const std::string &name) : type(name)
{
	std::cout << "String constructor of ANIMAL called: " << name << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor of ANIMAL called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy constructor of ANIMAL called" << std::endl;
	type = other.type;
}

Animal &Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void Animal::makeSound()
{
	std::cout << "ANIMAL SOUND!" << std::endl;
}
