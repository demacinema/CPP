/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:41:03 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:41:04 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
    std::cout << "\033[32mHello from Character constructor\033[0m" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::~Character()
{
    std::cout << "\033[31mBye from Character destructor\033[0m" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
}

Character::Character(const Character &copy_const) : _name(copy_const._name)
{
    std::cout << "\033[32mHello from Character copy constructor\033[0m" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (copy_const._inventory[i])
            this->_inventory[i] = copy_const._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &assign_op)
{
    std::cout << "\033[32mHello from Character assignation operator\033[0m" << std::endl;
    if (this != &assign_op)
    {
        this->_name = assign_op._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (assign_op._inventory[i])
                this->_inventory[i] = assign_op._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = m;
            return ;
        }
    }
    std::cout << "\033[30mInventory is full\033[0m" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "\033[30munequipped\033[0m" << std::endl;
        return ;
    }
    this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
}