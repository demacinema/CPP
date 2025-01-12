/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:24 by demrodri          #+#    #+#             */
/*   Updated: 2025/01/12 01:08:20 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() //: _type("Dog")
{
	// setType("Dog");
	_type = "Dog";
	std::cout << "Default constructor of DOG called: " << _type << std::endl;
	_brain = new Brain();
}

Dog::Dog(const std::string &name) //: _type(name)
{
	_type = name;
	std::cout << "String constructor of DOG called: " << name << std::endl;
}

Dog::~Dog()
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Destructor of DOG called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	if (_brain)
		delete _brain;
}

// Dog::Dog(const Dog& other) : Animal()
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Copy constructor of DOG called" << std::endl;
	// _type = other._type;
	*this = other;
}

Dog &Dog::operator=(const Dog& other)
{
    //  std::cout << "Hello from Dog assignment operator" << std::endl;
    //  if (this != &assign_op)
    //     _type_ = assign_op._type_;
    // return (*this);
	std::cout << "Assignment operator of DOG called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		// _type = other._type;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "DOG SOUND!" << std::endl;
}