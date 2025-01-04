/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:24 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/04 20:17:13 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() //: type("Dog")
{
	type = "Dog";
	std::cout << "Default constructor of DOG called: " << type << std::endl;
}

Dog::Dog(const std::string &name) //: type(name)
{
	type = name;
	std::cout << "String constructor of DOG called: " << name << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor of DOG called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

Dog::Dog(const Dog& other) : Animal()
{
	std::cout << "Copy constructor of DOG called" << std::endl;
	type = other.type;
}

Dog &Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void Dog::makeSound()
{
	std::cout << "DOG SOUND!" << std::endl;
}