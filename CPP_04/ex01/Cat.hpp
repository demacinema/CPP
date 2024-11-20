/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:38:31 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:38:32 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;
public:
    Cat();
    ~Cat();

    Cat(const Cat& copy_const);
    Cat& operator=(const Cat& assign_op); 
    void makeSound() const;
};

#endif