/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:37:14 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:37:15 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    setType("Dog");
    std::cout << "Hello from Dog Constructor" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Bye from Dog Destructor" << std::endl;
}

Dog::Dog(const Dog& copy_const) : Animal(copy_const)
{
    std::cout << "Hello from Dog copy constructor" << std::endl;
    *this = copy_const;
}

Dog& Dog::operator=(const Dog& assign_op)
{
     std::cout << "Hello from Dog assignment operator" << std::endl;
     if (this != &assign_op)
        _type_ = assign_op._type_;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}