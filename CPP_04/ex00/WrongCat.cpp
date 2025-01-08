/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:37:46 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/09 00:44:57 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	// setType("Wrong Cat");
	// std::cout << "Hello from Wrong cat Constructor" << std::endl;
	_type_ = "WrongCat";
	std::cout << "Default constructor of WRONGCAT called: " << _type_ << std::endl;
}

WrongCat::~WrongCat()
{
	// std::cout << "Bye from Wrong Cat Destructor" << std::endl;
	std::cout << "Destructor of WRONGCAT called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy_const) : WrongAnimal() //(copy_const)
{
	// std::cout << "Hello from Wrong Cat Copy Constructor" << std::endl;
	// *this = copy_const;
	std::cout << "Copy constructor of WRONGCAT called" << std::endl;
	_type_ = copy_const._type_;
}

WrongCat& WrongCat::operator=(const WrongCat& assign_op)
{
	std::cout << "Hello from Wrong Cat assignment operator" << std::endl;
	if (this != &assign_op)
		_type_ = assign_op._type_;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Cat can't say Meow" << std::endl;
}