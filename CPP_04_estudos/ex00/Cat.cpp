/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:29 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/09 01:19:04 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() //: _type("Cat")
{
	_type = "Cat";
	std::cout << "Default constructor of CAT called: " << _type << std::endl;
}

Cat::Cat(const std::string &name) //: _type(name)
{
	_type = name;
	std::cout << "String constructor of CAT called: " << name << std::endl;
}

Cat::~Cat()
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Destructor of CAT called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

Cat::Cat(const Cat& other) : Animal()
{
	std::cout << "Copy constructor of CAT called" << std::endl;
	_type = other._type;
}

Cat &Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "CAT SOUND!" << std::endl;
}