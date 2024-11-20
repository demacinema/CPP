/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:34:37 by demacinema        #+#    #+#             */
/*   Updated: 2024/11/20 22:34:38 by demacinema       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

Claptrap::Claptrap() : _name("Default"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Default constructor called " << _name << std::endl;
};

Claptrap::Claptrap(const std::string &name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "constructor called " << _name << std::endl;
};

Claptrap::~Claptrap()
{
	std::cout << "deconstructor called " << _name << std::endl;
}

Claptrap &Claptrap::operator=(const Claptrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_ad = other._ad;
	}
	return (*this);
}

std::string	Claptrap::getName(void) const
{
	return (_name);
}

int	Claptrap::getHp(void) const
{
	return (_hp);
}

int	Claptrap::getEp(void) const
{
	return (_ep);
}

int	Claptrap::getAd(void) const
{
	return (_ad);
}

void	Claptrap::setHp(int value)
{
	_hp = value;
}
void	Claptrap::setEp(int value)
{
	_ep = value;
}
void	Claptrap::setAd(int value)
{
	_ad = value;
}
		
void	Claptrap::attack(const std::string &target)
{
	if (_ep > 0 && _hp > 0)
	{
		std::cout << _name <<" attacks " << target << " for " << getAd() << " points of damage!" << std::endl;
		setEp(_ep - 1);
	}
	else if (_ep == 0 && _hp > 0)
		std::cout << "no energy left for this action!" << std::endl;
	else
		std::cout << _name << "is dead D:" << std::endl;
}

void	Claptrap::takeDamage(unsigned int amount)
{	
	if (static_cast<unsigned int>(_hp) > amount)
	{
		setHp(_hp - amount);
		std::cout << _name <<" takes " << amount << " points of damage!"<< std::endl;
		std::cout << _name <<" has " << getHp() << " Hp left"<< std::endl;
	}
	else
	{
		setHp(0);
		std::cout << _name << " is dead D:" << std::endl;
	}
}

void	Claptrap::beRepaired(unsigned int amount)
{
	if (_ep > 0 && _hp > 0)
	{
		std::cout << "Claptrap repaires itself for " << amount  << std::endl;
		setEp(_ep - 1);
	}
	else if (_ep == 0 && _hp > 0)
		std::cout << "no energy left for this action!" << std::endl;
	else
		std::cout << "Cant do that " << _name << " is dead D:" << std::endl;
}
