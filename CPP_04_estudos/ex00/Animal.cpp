/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:50:22 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/09 00:07:22 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Default constructor of ANIMAL called: " << _type << std::endl;
}

Animal::Animal(const std::string &name) : _type(name)
{
	std::cout << "String constructor of ANIMAL called: " << name << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor of ANIMAL called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	// delete(this); ?????
}

Animal::Animal(const Animal& other)
{
	// *this = other;
	std::cout << "Copy constructor of ANIMAL called" << std::endl;
	_type = other._type;
}

Animal &Animal::operator=(const Animal& other)
{
	std::cout << "Assignment operator of ANIMAL called" << std::endl;
	if (this != &other)
	{
		// _type = other._type;
		this->_type = other._type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::setType(const std::string& type)
{
	_type = type;
}

void Animal::makeSound() const
{
	std::cout << "ANIMAL SOUND!" << std::endl;
}