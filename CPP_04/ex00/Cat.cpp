/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:37:02 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/09 00:15:48 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    setType("Cat");
    std::cout << "Default constructor of CAT called: " << _type_ << std::endl;
}

Cat::Cat(std::string type)
{
	setType(type);
	std::cout << "String constructor of CAT called:" << type << std::endl;
}

Cat::~Cat()
{
    // std::cout << "Bye from Cat Destructor" << std::endl;
	std::cout << "Destructor of CAT called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

Cat::Cat(const Cat& copy_const) : Animal () //: Animal(copy_const)
{
    // std::cout << "Hello from Cat copy  Constructor" << std::endl;
    // *this = copy_const;
	std::cout << "Copy constructor of CAT called" << std::endl;
	_type_ = copy_const._type_;
}

Cat& Cat::operator=(const Cat& assign_op)
{
    // std::cout << "Hello from Cat assignment operator" << std::endl;
    // if (this != &assign_op)
    //     _type_ = assign_op._type_;
    // return (*this);
	if (this != &assign_op)
	{
		this->_type_ = assign_op._type_;
	}
	return (*this);
}

void Cat::makeSound() const
{
    // std::cout << "Meo" << std::endl;
	std::cout << "CAT SOUND!" << std::endl;
}