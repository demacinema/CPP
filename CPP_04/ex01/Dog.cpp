/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:38:37 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/12 01:01:02 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    setType("Dog");
    // std::cout << "Hello from Dog Constructor" << std::endl;
	std::cout << "Default constructor of DOG called: " << _type_ << std::endl;
    _brain = new Brain();

}

Dog::~Dog()
{
    // std::cout << "Bye from Dog Destructor" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Destructor of DOG called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
    if (_brain)
        delete _brain;
}

Dog::Dog(const Dog& copy_const) : Animal(copy_const)
{
    // std::cout << "Hello from Dog copy constructor" << std::endl;
	std::cout << "Copy constructor of DOG called" << std::endl;
    *this = copy_const;
}

Dog& Dog::operator=(const Dog& assign_op)
{
    //  std::cout << "Hello from Dog assignment operator" << std::endl;
	std::cout << "Assignment operator of DOG called" << std::endl;
     if (this != &assign_op)
     {
        _type_ = assign_op._type_;
        _brain = new Brain(*assign_op._brain);
     }
    return (*this);
}

void Dog::makeSound() const
{
    // std::cout << "Woof" << std::endl;
	std::cout << "DOG SOUND!" << std::endl;
}