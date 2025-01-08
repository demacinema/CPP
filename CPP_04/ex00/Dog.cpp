/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:37:14 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/09 00:24:40 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    setType("Dog");
    // std::cout << "Hello from Dog Constructor" << std::endl;
	std::cout << "Default constructor of DOG called: " << _type_ << std::endl;
}

Dog::Dog(std::string type)
{
	// setType(type);
	// std::cout << "Hello from string Dog Constructor" << std::endl;
	_type_ = type;
	std::cout << "String constructor of DOG called: " << type << std::endl;
}

Dog::~Dog()
{
    // std::cout << "Bye from Dog Destructor" << std::endl;
	std::cout << "Destructor of DOG called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

Dog::Dog(const Dog& copy_const) : Animal() //: Animal(copy_const)
{
    // std::cout << "Hello from Dog copy constructor" << std::endl;
    // *this = copy_const;
	std::cout << "Copy constructor of DOG called" << std::endl;
	_type_ = copy_const._type_;
}

Dog& Dog::operator=(const Dog& assign_op)
{
    //  std::cout << "Hello from Dog assignment operator" << std::endl;
    //  if (this != &assign_op)
    //     _type_ = assign_op._type_;
    // return (*this);
	if (this != &assign_op)
	{
		this->_type_ = assign_op._type_;
	}
	return (*this);
}

void Dog::makeSound() const
{
    // std::cout << "Woof" << std::endl;
	std::cout << "DOG SOUND!" << std::endl;
}