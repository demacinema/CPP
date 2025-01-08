/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:37:07 by demacinema        #+#    #+#             */
/*   Updated: 2025/01/09 00:09:40 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{

public:
    Cat();
	Cat(std::string type);
    ~Cat();
    Cat(const Cat& copy_const);
    Cat& operator=(const Cat& assign_op);
	
    void makeSound() const;
};

#endif