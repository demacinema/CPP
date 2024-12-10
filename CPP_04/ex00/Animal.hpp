/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:36:56 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:36:57 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{

protected:
	std::string _type_;
public:
	Animal();
	virtual ~Animal();

	Animal(const Animal& copy_const);
	Animal& operator=(const Animal& assign_op);

	virtual void makeSound() const;
	std::string getType() const;
	void setType(std::string type);
};

#endif