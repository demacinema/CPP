/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:36:51 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:36:52 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type_("Animal")
{
	std::cout << "Hello from " << _type_ << " constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Bye from Animal Destructor" << std::endl;
}

Animal::Animal(const Animal& copy_const)
{
	std::cout << "Hello from Animal copy constructor" << std::endl;
	*this = copy_const;
}

Animal& Animal::operator=(const Animal& assign_op)
{
		std::cout << "Hello from Animal assignment operator" << std::endl;
		if (this != &assign_op)
			_type_ = assign_op._type_;
		return *this;
}

void Animal::makeSound() const
{
	std::cout << "Sound from Animal Class" << std::endl;	
}

void Animal::setType(std::string type)
{
		_type_ = type;
}
std::string Animal::getType() const
{
	return _type_;
}