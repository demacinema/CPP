/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:37:35 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/09 00:39:18 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() //: _type_("Wrong Animal")
{
	// std::cout << "Hello from Wrong Animal Constructor" << std::endl;
	_type_ = "WrongAnimal";
	std::cout << "Default constructor of WRONGANIMAL called: " << _type_ << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	// std::cout << "Bye from Wrong Animal Destructor" << std::endl;
	std::cout << "Destructor of WRONGANIMAL called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy_const)
{
	// std::cout << "Hello from Wrong Animal Copy Constructor" << std::endl;
	// *this = copy_const;
	std::cout << "Copy constructor of WRONGANIMAL called" << std::endl;
	_type_ = copy_const._type_;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assign_op)
{
	std::cout << "Hello from Wrong Animal assignment operator" << std::endl;
	if (this != &assign_op)
		_type_ = assign_op._type_;
	return (*this);
}

void WrongAnimal::setType(std::string type)
{
	_type_ = type;
}

std::string WrongAnimal::getType() const
{
	return (_type_);
}

void WrongAnimal::makeSound() const
{
	// std::cout << "wrong Animal sound" << std::endl;
	std::cout << "WRONGANIMAL SOUND!" << std::endl;
}