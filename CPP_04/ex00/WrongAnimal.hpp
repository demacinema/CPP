/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:37:41 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:37:42 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string _type_;
public:
    WrongAnimal();
    virtual ~WrongAnimal();

    WrongAnimal(const WrongAnimal& copy_const);
    WrongAnimal& operator=(const WrongAnimal& assign_op);
    void setType(std::string type);
    std::string getType() const;
    void makeSound() const;
};

#endif