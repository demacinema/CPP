/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:38:43 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:38:44 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private: 
    Brain *_brain;
public:
    Dog();
    ~Dog();

    Dog(const Dog& copy_const);
    Dog& operator=(const Dog& assign_op); 
    void makeSound() const;
};

#endif