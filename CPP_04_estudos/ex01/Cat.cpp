/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:29 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/12 01:03:17 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() //: _type("Cat")
{
	_type = "Cat";
	std::cout << "Default constructor of CAT called: " << _type << std::endl;
	_brain = new Brain();
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
	if (_brain)
		delete _brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Copy constructor of CAT called" << std::endl;
	_type = other._type;
}

Cat &Cat::operator=(const Cat& other)
{
	std::cout << "Assignment operator of CAT called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "CAT SOUND!" << std::endl;
}