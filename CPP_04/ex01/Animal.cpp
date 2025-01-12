/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:38:01 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/12 00:13:45 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type_("Animal")
{
	// std::cout << "Hello from " << _type_ << " constructor" << std::endl;
	std::cout << "Default constructor of ANIMAL called: " << _type_ << std::endl;
}

Animal::~Animal()
{
	// std::cout << "Bye from Animal Destructor" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Destructor of ANIMAL called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

Animal::Animal(const Animal& copy_const)
{
	// std::cout << "Hello from Animal copy constructor" << std::endl;
	std::cout << "Copy constructor of ANIMAL called" << std::endl;
	*this = copy_const;
}

Animal& Animal::operator=(const Animal& assign_op)
{
		// std::cout << "Hello from Animal assignment operator" << std::endl;
		std::cout << "Assignment operator of ANIMAL called" << std::endl;
		if (this != &assign_op)
			_type_ = assign_op._type_;
		return *this;
}

void Animal::makeSound() const
{
	// std::cout << "Sound from Animal Class" << std::endl;
	std::cout << "Assignment operator of ANIMAL called" << std::endl;
}

void Animal::setType(std::string type)
{
		_type_ = type;
}
std::string Animal::getType() const
{
	return _type_;
}